/*
 * Copyright (c) 2019 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Test vectors published in RFC2202 */

#include <vppinfra/clib.h>
#include <vnet/crypto/crypto.h>
#include <unittest/crypto/crypto.h>

static u8 sha1_tc1_key[] = {
  0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
  0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
  0x0b, 0x0b, 0x0b, 0x0b
};

static char sha1_tc1_data[8] = "Hi There";

static u8 sha1_tc1_digest[] = {
  0xb6, 0x17, 0x31, 0x86, 0x55, 0x05, 0x72, 0x64,
  0xe2, 0x8b, 0xc0, 0xb6, 0xfb, 0x37, 0x8c, 0x8e,
  0xf1, 0x46, 0xbe, 0x00
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (rfc_2202_sha1_tc1) = {
  .name = "RFC2202 HMAC-SHA-1 TC1",
  .op = VNET_CRYPTO_OP_SHA1_HMAC,
  .key = TEST_DATA (sha1_tc1_key),
  .data = TEST_DATA (sha1_tc1_data),
  .expected = TEST_DATA (sha1_tc1_digest),
};
/* *INDENT-ON* */

static u8 sha1_tc7_key[80] = {
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
};

static char sha1_tc7_data[73] =
  "Test Using Larger Than Block-Size Key and Larger Than One Block-Size Data";

static u8 sha1_tc7_digest[20] = {
  0xe8, 0xe9, 0x9d, 0x0f, 0x45, 0x23, 0x7d, 0x78,
  0x6d, 0x6b, 0xba, 0xa7, 0x96, 0x5c, 0x78, 0x08,
  0xbb, 0xff, 0x1a, 0x91
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (rfc_2202_sha1_tc7) = {
  .name = "RFC2202 HMAC-SHA-1 TC7",
  .op = VNET_CRYPTO_OP_SHA1_HMAC,
  .key = TEST_DATA (sha1_tc7_key),
  .data = TEST_DATA (sha1_tc7_data),
  .expected = TEST_DATA (sha1_tc7_digest),
};
/* *INDENT-ON* */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
