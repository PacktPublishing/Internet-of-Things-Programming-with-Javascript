Python 3.4.4 (v3.4.4:737efcadf5a6, Dec 20 2015, 20:20:57) [MSC v.1600 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> 
import serial

Arduino_UNO = serial.Serial('/dev/ttyACM0', 9600)
print("Hello From Arduino!")

while True:
      command = raw_input('Enter the command ')
      Arduino_UNO.write(command)
      if command == 'H':
            print('LED ON')
      elif command == 'L':
            print('LED OFF')
arduino_UNO.close()
