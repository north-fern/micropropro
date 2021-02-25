/**
* Morgan Strong 2021
* Some base code/references from pico-examples, blink, clock
* https://github.com/raspberrypi/pico-examples
* https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/hello_serial.c
*/


#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

int check_level();
int level_one();
int level_three();
int level_four();
void print_level(int LEVEL);
void send_message(int LEVEL);

void main() {
    base_num = 1
    while (true) {
        for(i = 0, i < base_num, i++){
            send_message(base_num);
            base_num1 = check_level(base_num);
            print_level(base_num1);
            base_num2 = check_level(base_num1);
        }
        base_num = base_num2;
    }
}


void print_level(int LEVEL){
    uint LED = 25;
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    for(i = 0, i < LEVEL, i++){
        gpio_put(LED, 1);
        sleep_ms(100);
        gpio_put(LED, 0);
        sleep_ms(100);
    }
    return;
}

int check_level(int base_num){
    
    if(base_num == 1){
        base_num = level_one();
    } else if(base_num == 2){
        base_num = level_two();
    } else if(base_num == 3){
        base_num = level_three();
    } else if(base_num == 4){
        base_num = level_four();
    }
}

int level_one(){
// set pin 20 low

    uint ONE = 20;
    gpio_init(ONE);
    ans = gpio_is_pulled_down(ONE);
    if(ans == true){
        return 2;
    } else{
        return 1;
    }
}

int level_two(){
// set pin 31 high

    uint TWO = 31;
    gpio_init(TWO);
    ans = gpio_is_pulled_up(TWO);
    if(ans == true){
        return 3;
    } else{
        return 2;
    }
}

int level_three(){
// set pin 22 low and 14 high

    uint three_low = 22;
    gpio_init(three_low);
    ans1 = gpio_is_pulled_down(three_low);
    uint three_high = 14;
    gpio_init(three_high);
    ans2 = gpio_is_pulled_down(three_high);
    if(ans1 == true && ans2 == true){
        return 4;
    } else{
        return 3;
    }
}

int level_four(){
    stdio_init_all();
    printf("PUZZLE SOLVED! Secret key: DEF8A1A487B3B3B9F2A3C7495D68272D166F7E0F7C65EB963E71B06A82AC81BE ")
// send finished message
    return 10;
}

void send_message(int LEVEL){
    char Message_1 = ".--. ..--- -----   .-.. --- .--"; //31 long
    char Message_2 = "... .-.. --.-  .-- -.- .-.. ..- .-- -...   .-. --.- ....   -.- .-.. .--- -.-"; //77 long
    char Message_3 = ".--. ..--- ..---   .-.. --- .--   .--. .---- ....-   .... .. --. ...."; //70 long
    
    if(LEVEL == 1){
        uint send_pin = 7;
        gpio_init(send_pin);
        gpio_set_dir(send_pin, GPIO_OUT);
        for(i = 0, i < 31, i++){
            if(Message_1[i] == "."){
                gpio_put(send_pin, 1);
                sleep_ms(25);
                gpio_put(send_pin, 0);
                sleep_ms(25);
            } else if(Message_1[i] == "_"){
                gpio_put(send_pin, 1);
                sleep_ms(50);
                gpio_put(send_pin, 0);
                sleep_ms(25);                
            } else {
                gpio_put(send_pin, 0);
                sleep_ms(25); 
            }
        }
    } else if(LEVEL == 2){
        uint send_pin = 12;
        gpio_init(send_pin);
        gpio_set_dir(send_pin, GPIO_OUT);
        for(i = 0, i < 77, i++){
            if(Message_2[i] == "."){
                gpio_put(send_pin, 1);
                sleep_ms(10);
                gpio_put(send_pin, 0);
                sleep_ms(10);
            } else if(Message_2[i] == "_"){
                gpio_put(send_pin, 1);
                sleep_ms(20);
                gpio_put(send_pin, 0);
                sleep_ms(10);                
            } else {
                gpio_put(send_pin, 0);
                sleep_ms(10); 
            }
        }
    } else if(LEVEL == 3){
        uint send_pin = 15;
        gpio_init(send_pin);
        gpio_set_dir(send_pin, GPIO_OUT);
        for(i = 0, i < 70, i++){
            if(Message_3[i] == "."){
                gpio_put(send_pin, 1);
                sleep_ms(10);
                gpio_put(send_pin, 0);
                sleep_ms(10);
            } else if(Message_3[i] == "_"){
                gpio_put(send_pin, 1);
                sleep_ms(20);
                gpio_put(send_pin, 0);
                sleep_ms(10);                
            } else {
                gpio_put(send_pin, 0);
                sleep_ms(10); 
            }
        }
    }
    return;
}