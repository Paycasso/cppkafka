/*
 * Copyright (c) 2016, Matias Fontanini
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef CPPKAFKA_CONFIGURATION_BASE_H
#define CPPKAFKA_CONFIGURATION_BASE_H

#include <string>

namespace cppkafka {

template <typename Concrete>
class ConfigurationBase {
public:
    /**
     * Sets a bool value
     */
    void set(const std::string& name, bool value) {
        proxy_set(name, value ? "true" : "false");
    }

    /**
     * Sets a value of any integral value
     */
    template <typename T,
              typename = typename std::enable_if<std::is_integral<T>::value>::type>
    void set(const std::string& name, T value) {
        proxy_set(name, std::to_string(value));
    }

    /**
     * Sets a cstring value
     */
    void set(const std::string& name, const char* value) {
        proxy_set(name, value);
    }
private:
    void proxy_set(const std::string& name, const std::string& value) {
        static_cast<Concrete&>(*this).set(name, value);
    }
};

} // cppkafka

#endif // CPPKAFKA_CONFIGURATION_BASE_H
