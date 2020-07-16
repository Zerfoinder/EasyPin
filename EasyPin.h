/**
 * ----------------------------------------------------------------
 * Copyright (C) 2020  Luis Acosta <zerfoinder@gmail.com>
 *
 * EasyPin library, This library is used to manage in a simple way all
 * Arduino pins.
 *
 * www.github.com/Zerfoinder/EasyPin (github as default source provider)
 *
 * This file is part of EasyPin library.
 *
 * EasyPin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyPin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * ----------------------------------------------------------------
 */

/**
 *  name:         EasyPin
 *  version:      1.1
 *  Author:       Luis Acosta <zerfoinder@gmail.com>
 *  Date:         2020-07-15
 *  Description:  EasyPin is a library for simplify arduino pins management.
 */

#ifndef TOOLS_EASY_PIN_H
#define TOOLS_EASY_PIN_H

namespace zsoft::tools {

    /**
     * @brief      PinType is an enum to define pin mode.
     */
    enum PinType {
        OUT = 0,   // OUTPUT
        IN = 1,    // INPUT
        PULLUP = 2 // INPUT_PULLUP
    };



    /**
     * @brief      This class describes an EasyPin.
     */
    class EasyPin {
      public:
        /**
         * @brief      Constructs a new instance.
         *
         * @param[in]  pinNumber  Arduino board pin number
         * @param[in]  ptype      PinType
         */
        EasyPin(int pinNumber, PinType ptype);

        /**
         * @brief      Initialize arduino pin, it should run always in setup section.
         */
        void init();

        /**
         * @brief      Turns on (set to HIGH) an Arduino pin.
         */
        void on();

        /**
         * @brief      Turns off (set to LOW) an Arduino pin.
         */
        void off();

        /**
         * @brief      toggle Arduino pin state (From ON to OFF, or from OFF to ON).
         */
        void toggle();

        /**
         * @brief      Set value for an Arduino PWM pin.
         *
         * @note       For PWM pins, accepts values between 0-255.
         *
         * @param[in]  value  The value
         */
        void setValue(int value);

        /**
         * @brief      Returns the current state of Arduino pin.
         *
         * @return     Both type of pins (PWM/Digital) returns False on LOW and
         *             returns True for any other value.
         */
        bool state();

        /**
         * @brief      Returns value  PWM pin returns the current value. Input
         *             pin returns always 0.
         *
         *             It works for PWM pins.
         *
         * @return     Returns 0 if is OFF, Return 1 if is ON. PWM returns value
         *             (0-255)
         */
        int value();

        /**
         * @brief      Returns the current value of Arduino INPUT pin direct
         *             from board.
         *
         * @return     Digital pin returns HIGH or LOW. Analog pin returns the
         *             current value. Output pin returns always 0.
         */
        unsigned long readValue();

      protected:

      private:
        /** Arduino board Pin number. */
        int _pinNumber;

        /** Pin value.
        * OFF: 0, ON: 1,
        * (For PWM 0-255 for brightness)
        */
        int _value;

        /** Pin state. */
        bool _state;

        /** Pin type. */
        PinType _type;

    }; // end class EasyPin

} // end namespace common::tools

#endif // TOOLS_EASY_PIN_H
