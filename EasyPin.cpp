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

#include <Arduino.h>
#include "EasyPin.h"

namespace zsoft::tools {

    EasyPin::EasyPin(int pinNumber, PinType ptype) {
        _pinNumber = pinNumber;
        _value = 0;
        _state = false;
        _type = ptype;
    }

    void EasyPin::init() {
        switch (_type) {
        case PinType::OUT:
            pinMode(_pinNumber, OUTPUT);
            break;
        case PinType::IN:
            pinMode(_pinNumber, INPUT);
            break;
        case PinType::PULLUP:
            pinMode(_pinNumber, INPUT_PULLUP);
            break;
        }
    }

    void EasyPin::on() {
        if (_type == PinType::OUT) {
            _state = true;
            _value = 255;
            digitalWrite(_pinNumber, HIGH);
        }
    }

    void EasyPin::off() {
        if (_type == PinType::OUT) {
            _state = false;
            _value = 0;
            digitalWrite(_pinNumber, LOW);
        }
    }

    void EasyPin::toggle() {
        if (_type == PinType::OUT) {
            if (_state) {
                off();
            } else {
                on();
            }
        }
    }

    void EasyPin::setValue(int value) {
        if (_type == PinType::OUT) {
            if (value <= 0) {
                value = 0;

                _value = value;
                _state = false;
                analogWrite(_pinNumber, _value);
            } else {
                if (value > 255) {
                    value = 255;
                }
                _value = value;
                _state = true;
                analogWrite(_pinNumber, _value);
            }
        }
    }

    bool EasyPin::state() {
        return _state;
    }

    int EasyPin::value() {
        return _value;
    }

    unsigned long EasyPin::readValue() {
        unsigned long readValue = 0;

        if (_type == PinType::IN || _type == PinType::PULLUP ) {
            readValue = digitalRead(_pinNumber);
        }

        return readedValue;
    }
} // end namespace tools
