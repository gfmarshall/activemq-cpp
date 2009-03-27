/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "StandardOutputStream.h"

#include <apr.h>
#include <apr_general.h>
#include <apr_pools.h>

using namespace decaf;
using namespace decaf::internal;
using namespace decaf::internal::io;

////////////////////////////////////////////////////////////////////////////////
StandardOutputStream::StandardOutputStream() {
}

////////////////////////////////////////////////////////////////////////////////
StandardOutputStream::~StandardOutputStream() {
}

////////////////////////////////////////////////////////////////////////////////
void StandardOutputStream::write( unsigned char c )
    throw ( decaf::io::IOException ) {

    std::cout << c;
}

////////////////////////////////////////////////////////////////////////////////
void StandardOutputStream::write( const std::vector<unsigned char>& buffer )
    throw ( decaf::io::IOException ) {

    if( buffer.empty() ){
        return;
    }

    this->write( &buffer[0], 0, buffer.size() );
}

////////////////////////////////////////////////////////////////////////////////
void StandardOutputStream::write( const unsigned char* buffer,
                                       std::size_t offset,
                                       std::size_t len )
    throw ( decaf::io::IOException, lang::exceptions::NullPointerException ) {

    if( buffer == NULL ) {
        throw lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "StandardOutputStream::write - Passed buffer is null." );
    }

    if( offset > len ) {
        throw decaf::io::IOException(
            __FILE__, __LINE__,
            "StandardOutputStream::write - offset passed is greater than length" );
    }

	for( std::size_t i = 0; i < len; ++i ) {
        std::cout << buffer[i+offset];
    }
}

////////////////////////////////////////////////////////////////////////////////
void StandardOutputStream::flush() throw ( decaf::io::IOException ){
    std::cout.flush();
}
