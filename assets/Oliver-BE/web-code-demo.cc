#include <iostream>
#include <vector>
#include <string>

#include "web/init.h"
#include "web/Document.h"
#include "utils.h"
#include "../js_utils.h"
#include "../../base/map.h"

namespace UI = emp::web;
UI::Document doc("emp_d3_test"); 

int MultiplyPair(int x, int y) { return x * y; }

// NOTE: this can't exist inside of main()
EM_JS(int, Multiply, (int x, int y), {
    return x * y;
});


int main() {
  ///////////////////////////////////////
  // EM_ASM (inline JavaScript code)
  int x = 5;

  EM_ASM({
    const js_x = $0;
    console.log("js_x is: " + js_x);
  }, x);
  ///////////////////////////////////////


  ///////////////////////////////////////
  // EM_ASM_INT (return an int from JavaScript)
  int int_var = EM_ASM_INT({
    return 10;
  });

  std::cout << "int_var is: " << int_var << std::endl;
  ///////////////////////////////////////


  ///////////////////////////////////////
  // EM_ASM_DOUBLE (return a double from JavaScript)
  double double_var = EM_ASM_DOUBLE({
    return 10.1234;
  });

  std::cout <<  "double_var is: " << double_var << std::endl;
  ///////////////////////////////////////


  ///////////////////////////////////////
  // Passing a std::string into EM_ASM
  std::string string_input = "empirical";
  EM_ASM({
    const js_string_input = UTF8ToString($0);
    console.log("js_string_input is: " + js_string_input);
  }, string_input.c_str());
  ///////////////////////////////////////


  ///////////////////////////////////////
  // Pseduo-EM_ASM_STRING (PassStrToCpp) (return a string from JavaScript)
  EM_ASM({
    const string_var = "Hello world!";
    emp.PassStringToCpp(string_var);
  });
  
  std::string string_var = emp::pass_str_to_cpp();
  std::cout << "string_var is: " << string_var << std::endl;

  /*
    // THE OLD WAY
      
      std::string ReturnAString(std::string name) {
        char * buffer = (char *)EM_ASM_INT({
          var to_return = UTF8ToString($0);
          var buffer = Module._malloc(to_return.length+1);
          Module.stringToUTF8(to_return, buffer, lengthBytesUTF8(to_return)+1);
          return buffer;
        }, name.c_str());

        std::string resulting_str = std::string(buffer);
        free(buffer);
        return resulting_str;
      }

    // THE NEW WAY
      
      std::string ReturnAString(std::string name) {
        EM_ASM({
          var to_return = UTF8ToString($0);
          emp.PassStringToCpp(to_return);
        }, name.c_str());
        return emp::pass_str_to_cpp();
      }

    */
  ///////////////////////////////////////


  ///////////////////////////////////////
  // EM_JS (call JavaScript functions in C++)
  // See code outside of main()
  // EM_JS(int, Multiply, (int x, int y), {
  //   return x * y;
  // });

  int val_1 = 5;
  int val_2 = 4;
  int result = Multiply(val_1, val_2);
  std::cout << "Multiply result is " << result << std::endl;
  ///////////////////////////////////////

  ///////////////////////////////////////
  // JSWrap (call C++ functions in JavaScript)
  // See code outside of main()
  // int MultiplyPair(int x, int y) { return x * y; }
  
  size_t multiply_func_id = emp::JSWrap(MultiplyPair, "MultiplyPair");

  EM_ASM({
    const result = emp.MultiplyPair(8, 9);
    console.log("MultiplyPair result is: " + result);
  });

  emp::JSDelete(multiply_func_id);
  ///////////////////////////////////////


  ///////////////////////////////////////
  // emp::pass_array_to_javascript
  emp::array<double, 3> testArray = {1.1, 2.2, 3.3};
  emp::pass_array_to_javascript(testArray);

  EM_ASM({
    const js_array = emp_i.__incoming_array;
    console.log(js_array);
  }); 

  // emp::pass_array_to_cpp
  EM_ASM({
    // NOTE: when creating arrays / dictionaries in EM_ASM always put parentheses around them
    emp_i.__outgoing_array = ( [1.1, 2.2, 3.3] );
  });

  emp::array<double, 3> cpp_array;
  emp::pass_array_to_cpp(cpp_array);
  std::cout << cpp_array << std::endl;
  ///////////////////////////////////////


  ///////////////////////////////////////
  // emp::pass_map_to_javascript
  // using an emp::map
  emp::map<std::string, double> testMap = {{"test1", 1.01}, {"test2", 2.02}, {"test3", 3.03}};
  emp::pass_map_to_javascript(testMap);

  EM_ASM({
    const js_map = emp_i.__incoming_map;
    console.log(js_map);
  });

  // using two emp::arrays (one for keys, one for values)
  emp::array<std::string, 5> keysCpp = {"test1", "test2", "test3"};
  emp::array<std::string, 5> valsCpp = {"red", "blue", "purple"};
  emp::pass_map_to_javascript(keysCpp, valsCpp);

  EM_ASM({
    const js_map = emp_i.__incoming_map;
    console.log(js_map);
  });
  ///////////////////////////////////////

}