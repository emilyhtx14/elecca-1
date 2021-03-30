/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
/**   Christmas lights controller.    
      @file lights_emh13.c   
      @author Emily Huang 
      @email emh13@rice.edu 
      @date* 03/24/2021
      /
      
      /************************************************ *  constants (states) ***********************************************/
      #define     S_INIT      0   // initial
      #define     S_RED       1   // red lights on
      #define     S_GREEN     2   // green lights on
      #define     S_BLUE      3   // blue lights on
      #define     S_OFF       4   // off
      #define     M_RGB       0   // red, green, blue enabled
      #define     M_RB        1   // red, blue enabled
      #include <stdio.h>
      #include <stdlib.h>
      /************************************************ *  global variables ***********************************************/
      int state;                  // tracks the current state
      int mode;                   // tracks the light mode
      /************************************************ *  function prototypes ***********************************************/ 
      // state machine control 
      int get_next_state(int timer);
      void update_state(int next_state);
      
      // actions for each state 
      void turn_on(void);
      void light_red(void);
      void light_green(void);
      void light_blue(void);
      void turn_off(void);
      /************************************************ *  main ***********************************************/
      int main(int argc, char *argv[])
      {    
          // argc is number of command line arguments
          // argv is an array
          //      argv[0] is program name
          //      argv[1], argv[2], ... are command line arguments (as ascii strings)
          
        if (argc == 2)
            mode = atoi(argv[1]);   // ascii to integer
            
        else if (argc > 2)    
        {        
            printf("Error: Too many arguments supplied.\n");
            exit(1);    
        }    
        else    
        {        
            printf("Error: One argument expected.\n");
            exit(1);
        }    
        
        //prints mode
        printf("mode = %i\n", mode);
        
        if ((mode != M_RGB) && (mode != M_RB))
        {        
            printf("Error: unexpected mode (allowed values: 0, 1)");
            exit(1);
        }    
        
        state = S_INIT; // start in a fixed, known state
        int next_state;
        int timer = 12;
        
        // newly added code
        
        
        // set timer to 12 iterations
        int exit_flag = 0;
        
        // turn on the the lights
        while (exit_flag == 0)    
        {        
            // execute appropriate action for current state
            if (state == S_INIT){
                turn_on();
            }
            else if (state == S_OFF)
            {            
                // perform action for this state
                turn_off();
                
                // set exit flag
                exit_flag = 1;        
            }
            
            // actions for each color state
            else if (state == S_RED)
            {  
                light_red();
            }
            else if (state == S_GREEN) 
            {
                light_green();
            }
            else if (state == S_BLUE){
                light_blue();
            }
            
            // retrieve the next state and update   
            next_state = get_next_state(timer);
            update_state(next_state);
            // decrement timer        
            timer--;    
        }    
        
        return 0;
          
      }
      /************************************************ *  state control ***********************************************/
      int get_next_state(int timer)
      {

          int value;
          
          // return off state if timer has run out
          if (timer == 0)
          {
              return S_OFF;
          }
          
          // assign state names with timer modulo values
          if (mode == 0)
          {
              value = timer%3;
          }
          else if (mode == 1)
          {
              value = timer%2;
          }

          switch(value) {
              
              case 0:
                return S_RED;

              case 1:
                return S_BLUE;
                
              case 2:
                return S_GREEN;
          }
          
      }
      
      void update_state(int next_det) 
      {
          state = next_det;
      }
      
      /************************************************  *  state actions  ***********************************************/ 
      void turn_on(void) 
      {
         printf("ON, ");
         return;
      } 
      
      void light_red(void) 
      {     
          printf("red, ");
          return; 
      } 
      
      void light_green(void) 
      {     
          printf("green, ");
          return; 
      } 
      
      void light_blue(void) 
      {     
          printf("blue, ");
          return;
      } 
      
      void turn_off(void) 
      {     
          printf("OFF");
          return; 
      }

