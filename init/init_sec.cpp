/*
   Copyright (c) 2015, The Dokdo Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   File Name : init_sec.c
   Create Date : 2015.11.03
   Author : Sunghun Ra
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G925S")) {
        /* zerolteskt */
        property_set("ro.build.fingerprint", "samsung/zerolteskt/zerolteskt:5.1.1/LMY47X/G925SXXS3COK5:user/release-keys");
        property_set("ro.build.description", "zerolteskt-user 5.1.1 LMY47X G925SXXS3COK5 release-keys");
        property_set("ro.product.model", "SM-G925S");
        property_set("ro.product.device", "zerolteskt");
    } else if (strstr(bootloader, "G925K")) {
        /* zeroltektt */
        property_set("ro.build.fingerprint", "samsung/zeroltelgt/zeroltelgt:5.1.1/LMY47X/G925KXXS3COK5:user/release-keys");
        property_set("ro.build.description", "zeroltektt-user 5.1.1 LMY47X G925KXXS3COK5 release-keys");
        property_set("ro.product.model", "SM-G925K");
        property_set("ro.product.device", "zeroltektt");
    } else if (strstr(bootloader, "G925L")) {
        /* zeroltelgt */
        property_set("ro.build.fingerprint", "samsung/zeroltelgt/zeroltelgt:5.1.1/LMY47X/G925LXXS3COK5:user/release-keys");
        property_set("ro.build.description", "zeroltelgt-user 5.1.1 LMY47X G925LXXS3COK5 release-keys");
        property_set("ro.product.model", "SM-G925L");
        property_set("ro.product.device", "zeroltelgt");
    } else if (strstr(bootloader, "G925I")) {
        /* zeroltexx */
        property_set("ro.build.fingerprint", "samsung/zeroltexx/zeroltexx:5.1.1/LMY47X/G925IXXS3COK5:user/release-keys");
        property_set("ro.build.description", "zeroltexx-user 5.1.1 LMY47X G925IXXS3COK5 release-keys");
        property_set("ro.product.model", "SM-G925I");
        property_set("ro.product.device", "zeroltexx");
    } else {
        /* zeroltexx */
        property_set("ro.build.fingerprint", "samsung/zeroltexx/zeroltexx:5.1.1/LMY47X/G925FXXS3COK5:user/release-keys");
        property_set("ro.build.description", "zeroltexx-user 5.1.1 LMY47X G925FXXS3COK5 release-keys");
        property_set("ro.product.model", "SM-G925F");
        property_set("ro.product.device", "zeroltexx");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
