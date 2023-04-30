# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/gratt/esp/esp-idf/components/bootloader/subproject"
  "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader"
  "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix"
  "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix/tmp"
  "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix/src"
  "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Programation/ESP32/ESP32_S3/DevBoard2.0/Timer_Class_LED/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
