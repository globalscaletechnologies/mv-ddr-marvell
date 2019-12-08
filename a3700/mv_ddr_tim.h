/*
* ***************************************************************************
* Copyright (C) 2017 Marvell International Ltd.
* ***************************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* Neither the name of Marvell nor the names of its contributors may be used
* to endorse or promote products derived from this software without specific
* prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************
*/

static char ddr3_1cs_tim_pre[] = {
	"; Set DDR3 to 800MHz\n"
	"; Pre-init\n"
	"WRITE: 0xC0014008 0x00404500\n"
	"WRITE: 0xC0002000 0x00010000\n"
	"WRITE: 0xC0002004 0x00000000\n"
	"; DDR MAC init\n"
	"WRITE: 0xC0000340 0x00000303\n"
	"WRITE: 0xC0000344 0x0200000A\n"
	"WRITE: 0xC0000310 0x00200000\n"
	"WRITE: 0xC0000304 0x00000400\n"
	"WRITE: 0xC0000308 0x00000000\n"
/*
	"WRITE: 0xC0000200 0x000D0001\n"
	"WRITE: 0xC0000204 0x00000000\n"
	"WRITE: 0xC0000220 0x13020532\n"
*/
	"WRITE: 0xC0000044 0x00030200\n"
	"WRITE: 0xC00002c0 0x00006000\n"
	"WRITE: 0xC00002c4 0x00100020\n"
	"WRITE: 0xC0000058 0x0000143F\n"
	"WRITE: 0xC0000048 0x00000001\n"
	"WRITE: 0xC0000180 0x00010200\n"
	"WRITE: 0xC0000050 0x000001FF\n"
	"WRITE: 0xC000004c 0x00000000\n"
	"WRITE: 0xC0000054 0x00000480\n"
};

static char ddr3_1cs_tim_post[] = {
	"WRITE: 0xC00003c4 0x00000000\n"
	"WRITE: 0xC00003dc 0x00081239\n"
	"WRITE: 0xC00002c8 0x00000000\n"
	"WRITE: 0xC0000064 0x00000006\n"
	"; DDR PHY init\n"
	"WRITE: 0xC0001010 0x00300108\n"
	"WRITE: 0xC0001028 0x00000000\n"
	"WRITE: 0xC0001040 0x00000400\n"
	"WRITE: 0xC00010c0 0x80000000\n"
	"WRITE: 0xC00010d0 0x00000000\n"
	"WRITE: 0xC00010e0 0x00011FF0\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"WRITE: 0xC0001038 0x00000002\n"
	"WRITE: 0xC000103c 0x00000010\n"
	"WRITE: 0xC0001180 0x0000020A\n"
	"WRITE: 0xC0001184 0x0000020A\n"
	"WRITE: 0xC0001188 0x0000020A\n"
	"WRITE: 0xC000118c 0x0000020A\n"
	"WRITE: 0xC0001190 0x0000020A\n"
	"WRITE: 0xC0001194 0x0000020A\n"
	"WRITE: 0xC0001198 0x0000020A\n"
	"WRITE: 0xC000119c 0x0000020A\n"
	"WRITE: 0xC00011a0 0x0000020A\n"
	"WRITE: 0xC0001050 0x1F130000\n"
	"WRITE: 0xC0001054 0x20190000\n"
	"WRITE: 0xC0001074 0x20200000\n"
	"WRITE: 0xC0001058 0x08080000\n"
	"WRITE: 0xC000105c 0x08080000\n"
	"WRITE: 0xC0001060 0x08080000\n"
	"WRITE: 0xC0001064 0x08080000\n"
	"WRITE: 0xC0001068 0x08080000\n"
	"WRITE: 0xC000106c 0x08080000\n"
	"WRITE: 0xC0001070 0x08080000\n"
	"\n"
	";init read fifo pointer and OFF spec parameter\n"
	"WRITE: 0xC0001000 0x00044041\n"
	"WRITE: 0xC00003bc 0x02020404\n"
	"\n"
	";phyinit_sequence_sync2(1, 3, 2, 0)\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"OR_VAL: 0xC0001038 0x00000003\n"
	"WRITE: 0xC000103C 0x00000020\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"WRITE: 0xC0001020 0x20000000\n"
	"WRITE: 0xC0001020 0x40000000\n"
	"DELAY: 0x0000000A\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"DELAY: 0x0000000A\n"
	"\n"
	";DDRPHY Driver/Receiver & DQS internal Pullup/Pulldown settings\n"
	"WRITE: 0xC0001004 0xC4477889\n"
	"WRITE: 0xC0001008 0x05500FFA\n"
	"WRITE: 0xC000100c 0x0521DF77\n"
	"\n"
	";clear Terminal for DDR3 (<400MHz)\n"
	"AND_VAL: 0xC0001004 0xF00FFFFF\n"
	"\n"
	";DDRPHY pads POWERDOWN disable\n"
	"WRITE: 0xC0001030 0x03800000\n"
	"WRITE: 0xC0001034 0x00000000\n"
	"WRITE: 0xC0001090 0x00000000\n"
	"WRITE: 0xC0001094 0x00000000\n"
	"\n"
	";initC2Dofset\n"
	"WRITE: 0xC00010E0 0x00010001\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010002\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010004\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010008\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x003294A5\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010010\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x003294A5\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"\n"
	"; Trigger DDR init for channel 0\n"
	"WRITE: 0xC0000020 0x11000001\n"
	"WAIT_FOR_BIT_SET: 0xC0000008 0x00000001 0x00001000\n"
};

static char ddr3_2cs_tim_pre[] = {
	"; Set DDR3 to 800MHz\n"
	"; Pre-init\n"
	"WRITE: 0xC0014008 0x00404500\n"
	"WRITE: 0xC0002000 0x00010000\n"
	"WRITE: 0xC0002004 0x00000000\n"
	"; DDR MAC init\n"
	"WRITE: 0xC0000340 0x00000303\n"
	"WRITE: 0xC0000344 0x0200000A\n"
	"WRITE: 0xC0000310 0x00200000\n"
	"WRITE: 0xC0000314 0x00200000\n"
	"WRITE: 0xC0000304 0x00000400\n"
	"WRITE: 0xC0000308 0x00000000\n"
/*
	"WRITE: 0xC0000200 0x000D0001\n"
	"WRITE: 0xC0000204 0x00000000\n"
	"WRITE: 0xC0000208 0x200D0001\n"
	"WRITE: 0xC000020c 0x00000000\n"
	"WRITE: 0xC0000220 0x13000532\n"
	"WRITE: 0xC0000224 0x13000532\n"
*/
	"WRITE: 0xC0000044 0x00030200\n"
	"WRITE: 0xC00002c0 0x00006000\n"
	"WRITE: 0xC00002c4 0x00100020\n"
	"WRITE: 0xC0000058 0x0000143F\n"
	"WRITE: 0xC0000048 0x00000001\n"
	"WRITE: 0xC0000180 0x00010200\n"
	"WRITE: 0xC0000050 0x000001FF\n"
	"WRITE: 0xC000004c 0x00000000\n"
	"WRITE: 0xC0000054 0x00000480\n"
};

static char ddr3_2cs_tim_post[] = {
	"WRITE: 0xC00003c4 0x00000000\n"
	"WRITE: 0xC00003dc 0x00081239\n"
	"WRITE: 0xC00002c8 0x00000000\n"
	"WRITE: 0xC0000064 0x00000006\n"
	"; DDR PHY init\n"
	"WRITE: 0xC0001000 0x00045041\n"
	"WRITE: 0xC0001010 0x00300108\n"
	"WRITE: 0xC0001028 0x00000000\n"
	"WRITE: 0xC0001040 0x00000400\n"
	"WRITE: 0xC00010c0 0x80000000\n"
	"WRITE: 0xC00010d0 0x00000000\n"
	"WRITE: 0xC00010e0 0x00011FF0\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"WRITE: 0xC0001038 0x00000002\n"
	"WRITE: 0xC000103c 0x00000010\n"
	"WRITE: 0xC0001180 0x0000020A\n"
	"WRITE: 0xC0001184 0x0000020A\n"
	"WRITE: 0xC0001188 0x0000020A\n"
	"WRITE: 0xC000118c 0x0000020A\n"
	"WRITE: 0xC0001190 0x0000020A\n"
	"WRITE: 0xC0001194 0x0000020A\n"
	"WRITE: 0xC0001198 0x0000020A\n"
	"WRITE: 0xC000119c 0x0000020A\n"
	"WRITE: 0xC00011a0 0x0000020A\n"
	"WRITE: 0xC00011a4 0x0000020A\n"
	"WRITE: 0xC00011a8 0x0000020A\n"
	"WRITE: 0xC0001050 0x1F130000\n"
	"WRITE: 0xC0001054 0x20190000\n"
	"WRITE: 0xC0001074 0x20200000\n"
	"WRITE: 0xC0001058 0x08080000\n"
	"WRITE: 0xC000105c 0x08080000\n"
	"WRITE: 0xC0001060 0x08080000\n"
	"WRITE: 0xC0001064 0x08080000\n"
	"WRITE: 0xC0001068 0x08080000\n"
	"WRITE: 0xC000106c 0x08080000\n"
	"WRITE: 0xC0001070 0x28080000\n"
	";init read fifo pointer and OFF spec parameter\n"
	"WRITE: 0xC0001000 0x00044041\n"
	"WRITE: 0xC00003bc 0x02020404\n"
	"\n"
	";phyinit_sequence_sync2(1, 3, 2, 0)\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"OR_VAL: 0xC0001038 0x00000003\n"
	"WRITE: 0xC000103C 0x00000020\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"WRITE: 0xC0001020 0x20000000\n"
	"WRITE: 0xC0001020 0x40000000\n"
	"DELAY: 0x0000000A\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"DELAY: 0x0000000A\n"
	"\n"
	";DDRPHY Driver/Receiver & DQS internal Pullup/Pulldown settings\n"
	"WRITE: 0xC0001004 0xC4477889\n"
	"WRITE: 0xC0001008 0x05500FFA\n"
	"WRITE: 0xC000100c 0x0521DF77\n"
	"\n"
	";clear Terminal for DDR3 (<400MHz)\n"
	"AND_VAL: 0xC0001004 0xF00FFFFF\n"
	"\n"
	";DDRPHY pads POWERDOWN disable\n"
	"WRITE: 0xC0001030 0x03800000\n"
	"WRITE: 0xC0001034 0x00000000\n"
	"WRITE: 0xC0001090 0x00000000\n"
	"WRITE: 0xC0001094 0x00000000\n"
	"\n"
	";initC2Dofset\n"
	"WRITE: 0xC00010E0 0x00010001\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010002\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010004\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010008\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x003294A5\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010010\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x003294A5\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"\n"
	";set for CS1\n"
	"WRITE: 0xC00010E0 0x00020001\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020002\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020004\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020008\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x003294A5\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020010\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x003294A5\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"\n"
	"; Trigger DDR init for channel 0\n"
	"WRITE: 0xC0000020 0x13000001\n"
	"WAIT_FOR_BIT_SET: 0xC0000008 0x00000011 0x00001000\n"
};

static char ddr4_1cs_tim_pre[] = {
	"; Set DDR4 to 800MHz\n"
	"; Pre-init\n"
	"WRITE: 0xC0014008 0x00404500\n"
	"WRITE: 0xC0002000 0x00010000\n"
	"WRITE: 0xC0002004 0x00000000\n"
	"; DDR MAC init\n"
	"WRITE: 0xC0000340 0x00000303\n"
	"WRITE: 0xC0000344 0x0200000A\n"
	"WRITE: 0xC0000310 0x00100000\n"
	"WRITE: 0xC0000304 0x00000400\n"
	"WRITE: 0xC0000308 0x00000000\n"
/*
	"WRITE: 0xC0000200 0x000D0001\n"
	"WRITE: 0xC0000204 0x00000000\n"
	"WRITE: 0xC0000220 0x13020535\n"
*/
	"WRITE: 0xC0000044 0x00030200\n"
	"WRITE: 0xC00002C0 0x00006000\n"
	"WRITE: 0xC00002C4 0x00100030\n"
	"WRITE: 0xC0000058 0x0000143F\n"
	"WRITE: 0xC0000048 0x00000001\n"
	"WRITE: 0xC0000180 0x00010200\n"
	"WRITE: 0xC0000050 0x000001FF\n"
	"WRITE: 0xC000004C 0x00000000\n"
	"WRITE: 0xC0000054 0x00000480\n"
};

static char ddr4_1cs_tim_post[] = {
	"WRITE: 0xC00003C0 0x00020205\n"
	"WRITE: 0xC00003C4 0x00000003\n"
	"WRITE: 0xC00003DC 0x00081239\n"
	"WRITE: 0xC00002C8 0x00000000\n"
	"WRITE: 0xC0000064 0x00000006\n"
	"; DDR PHY init\n"
	"WRITE: 0xC0001010 0x00100100\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"WRITE: 0xC000101C 0x90118011\n"
	"WRITE: 0xC0001028 0x00000011\n"
	"WRITE: 0xC0001040 0x00000607\n"
	"WRITE: 0xC00010C0 0x51000000\n"
	"WRITE: 0xC0001050 0x15150000\n"
	"WRITE: 0xC0001054 0x20100000\n"
	"WRITE: 0xC0001074 0x15150000\n"
	"\n"
	";Setp7: init read fifo pointer and OFF spec parameter\n"
	"WRITE: 0xC0001000 0x00004032\n"
	"WRITE: 0xC00003bc 0x02020404\n"
	"\n"
	";Step8: phyinit_sequence_sync2(1, 3, 2, 0)\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"OR_VAL: 0xC0001038 0x00000003\n"
	"WRITE: 0xC000103C 0x00000020\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"WRITE: 0xC0001020 0x20000000\n"
	"WRITE: 0xC0001020 0x40000000\n"
	"DELAY: 0x0000000A\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"DELAY: 0x0000000A\n"
	"\n"
	";Step9: DDRPHY Driver/Receiver & DQS internal Pullup/Pulldown settings\n"
	"WRITE: 0xC0001004 0xD0133449\n"
	"WRITE: 0xC0001008 0xC770055A\n"
	"WRITE: 0xC000100C 0x5461DF77\n"
	"\n"
	";Step10:Skip for DDR4\n"
	"\n"
	";Step11: DDRPHY pads POWERDOWN disable\n"
	"WRITE: 0xC0001030 0x03800000\n"
	"WRITE: 0xC0001034 0x00000000\n"
	"WRITE: 0xC0001090 0x00000000\n"
	"WRITE: 0xC0001094 0x00000000\n"
	"\n"
	";Step12: initC2Dofset DDR4\n"
	"WRITE: 0xC00010E0 0x00010001\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010002\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010004\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010008\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00339CE7\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010010\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00339CE7\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"\n"
	";Step 13: Set DDRPHY read DAC default VREF/range value\n"
	"LOAD_SM_ADDR: SM0 0xC0001038\n"
	"AND_SM_VAL: SM0 0xFFCAFFFF\n"
	"OR_SM_VAL: SM0 0x00150000\n"
	"STORE_SM_ADDR: SM0 0xC0001038\n"
	"LOAD_SM_ADDR: SM0 0xC0001038\n"
	"AND_SM_VAL: SM0 0xC0FFFFFF\n"
	"OR_SM_VAL: SM0 0x32000000\n"
	"STORE_SM_ADDR: SM0 0xC0001038\n"
	"LOAD_SM_ADDR: SM0 0xC0001038\n"
	"AND_SM_VAL: SM0 0x3FFFFFFF\n"
	"OR_SM_VAL: SM0 0x40000000\n"
	"STORE_SM_ADDR: SM0 0xC0001038\n"
	"DELAY: 0x00000001\n"
	"\n"
	";Step 17: Set default value for DRAM DQ VREF\n"
	"OR_VAL: 0xC0000308 0x00000010\n"
	"OR_VAL: 0xC000030C 0x00800001\n"
	"WRITE: 0xC0000028 0x11004000\n"
	"LOAD_SM_ADDR: SM0 0xC000030C\n"
	"DELAY: 0x00000001\n"
	"AND_SM_VAL: SM0 0xFFC0FFFF\n"
	"OR_SM_VAL: SM0 0x250000\n"
	"STORE_SM_ADDR: SM0 0xC000030C\n"
	"WRITE: 0xC0000028 0x11004000\n"
	"DELAY: 0x00000001\n"
	"AND_VAL: 0xC0000308 0xFFFFFFEF\n"
	"WRITE: 0xC0000028 0x11004000\n"
	"DELAY: 0x00000001\n"
	"\n"
	";Step18: Trigger DDR init for channel 0\n"
	"WRITE: 0xC0000020 0x11000001\n"
	"\n"
	";Step19: Poll and wait for ddr init done\n"
	"WAIT_FOR_BIT_SET: 0xC0000008 0x00000001 0x00001000\n"
	"\n"
	"LOAD_SM_VAL: SM0 0\n"
	"\n"
	"LABEL: LP1\n"
	"LOAD_SM_ADDR: SM2 0xC000030C\n"
	"AND_SM_VAL: SM2 0xFFC0FFFF\n"
	"MOV_SM_SM: SM1 SM0\n"
	"LSHIFT_SM_VAL: SM1 0x10\n"
	"OR_SM_SM: SM2 SM1\n"
	"STORE_SM_ADDR: SM2 0xC000030C\n"
	"OR_VAL: 0xC0000028 0x11004000\n"
	"ADD_SM_VAL: SM0 0x1\n"
	"TEST_SM_AND_BRANCH: SM0 0x000000FF 0x00000032 < LP1\n"
	"\n"
	"AND_VAL: 0xC0000308 0xFFFFFFEF\n"
	"OR_VAL: 0xC0000028 0x11004000\n"
	"OR_VAL: 0xC0000308 0x00000010\n"
	"OR_VAL: 0xC000030C 0x00800001\n"
	"WRITE: 0xC0000028 0x11004000\n"
	"DELAY: 0x00000001\n"
	"\n"
	"LOAD_SM_ADDR: SM2 0xC000030C\n"
	"AND_SM_VAL: SM2 0xFFC0FFFF\n"
	"OR_SM_VAL: SM2 0x001C0000\n"
	"STORE_SM_ADDR: SM2 0xC000030C\n"
	"WRITE: 0xC0000028 0x11004000\n"
	"DELAY: 0x00000001\n"
	"\n"
	"AND_VAL: 0xC0000308 0xFFFFFFEF\n"
	"WRITE: 0xC0000028 0x11004000\n"
	"DELAY: 0x00000001\n"
};

static char ddr4_2cs_tim_pre[] = {
	"; Set DDR4 to 800MHz\n"
	"; Pre-init\n"
	"WRITE: 0xC0014008 0x00404500\n"
	"WRITE: 0xC0002000 0x00010000\n"
	"WRITE: 0xC0002004 0x00000000\n"
	"; DDR MAC init\n"
	"WRITE: 0xC0000340 0x00000303\n"
	"WRITE: 0xC0000344 0x0200000A\n"
	"WRITE: 0xC0000310 0x00100000\n"
	"WRITE: 0xC0000314 0x00100000\n"
	"WRITE: 0xC0000304 0x00000400\n"
	"WRITE: 0xC0000308 0x00000000\n"
/*
	"WRITE: 0xC0000200 0x000F0001\n"
	"WRITE: 0xC0000204 0x00000000\n"
	"; CS1\n"
	"WRITE: 0xC0000208 0x800F0001\n"
	"WRITE: 0xC000020C 0x00000000\n"
	"WRITE: 0xC0000220 0x13020639\n"
	"WRITE: 0xC0000224 0x13020639\n"
*/
	"WRITE: 0xC0000044 0x00030200\n"
	"WRITE: 0xC00002C0 0x00006000\n"
	"WRITE: 0xC00002C4 0x00100030\n"
	"WRITE: 0xC0000058 0x0000143F\n"
	"WRITE: 0xC0000048 0x00000001\n"
	"WRITE: 0xC0000180 0x00010200\n"
	"WRITE: 0xC0000050 0x000001FF\n"
	"WRITE: 0xC000004C 0x00000000\n"
	"WRITE: 0xC0000054 0x00000480\n"
};

static char ddr4_2cs_tim_post[] = {
	"WRITE: 0xC00003C0 0x00020205\n"
	"WRITE: 0xC00003C4 0x00000003\n"
	"WRITE: 0xC00003DC 0x00081239\n"
	"WRITE: 0xC00002C8 0x00000000\n"
	"WRITE: 0xC0000064 0x00000006\n"
	"; DDR PHY init\n"
	"WRITE: 0xC0001010 0x00100100\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"WRITE: 0xC000101C 0x90118011\n"
	"WRITE: 0xC0001028 0x00000011\n"
	"WRITE: 0xC0001040 0x00000607\n"
	"WRITE: 0xC00010C0 0x51000000\n"
	"WRITE: 0xC0001050 0x15150000\n"
	"WRITE: 0xC0001054 0x20100000\n"
	"WRITE: 0xC0001074 0x15150000\n"
	"\n"
	";Setp7: init read fifo pointer and OFF spec parameter\n"
	"WRITE: 0xC0001000 0x00004032\n"
	"WRITE: 0xC00003bc 0x02020404\n"
	"\n"
	";Step8: phyinit_sequence_sync2(1, 3, 2, 0)\n"
	"WRITE: 0xC0001014 0x00080200\n"
	"OR_VAL: 0xC0001038 0x00000003\n"
	"WRITE: 0xC000103C 0x00000020\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"WRITE: 0xC0001020 0x20000000\n"
	"WRITE: 0xC0001020 0x40000000\n"
	"DELAY: 0x0000000A\n"
	"WRITE: 0xC0001020 0x80000000\n"
	"DELAY: 0x0000000A\n"
	"\n"
	";Step9: DDRPHY Driver/Receiver & DQS internal Pullup/Pulldown settings\n"
	"WRITE: 0xC0001004 0xD0133449\n"
	"WRITE: 0xC0001008 0xC770055A\n"
	"WRITE: 0xC000100C 0x5461DF77\n"
	"\n"
	";Step10:Skip for DDR4\n"
	"\n"
	";Step11: DDRPHY pads POWERDOWN disable\n"
	"WRITE: 0xC0001030 0x03800000\n"
	"WRITE: 0xC0001034 0x00000000\n"
	"WRITE: 0xC0001090 0x00000000\n"
	"WRITE: 0xC0001094 0x00000000\n"
	"\n"
	";Step12: initC2Dofset DDR4\n"
	"WRITE: 0xC00010E0 0x00010001\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010002\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010004\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010008\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00339CE7\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00010010\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00339CE7\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"\n"
	";for CS1\n"
	"WRITE: 0xC00010E0 0x00020001\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020002\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020004\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00300C03\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020008\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00339CE7\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"WRITE: 0xC00010E0 0x00020010\n"
	"WRITE: 0xC00010D0 0x000C0300\n"
	"WRITE: 0xC00010D4 0x00300C03\n"
	"WRITE: 0xC00010D8 0x00339CE7\n"
	"WRITE: 0xC00010DC 0x00300C03\n"
	"\n"
	";Step 13: Set DDRPHY read DAC default VREF/range value\n"
	"LOAD_SM_ADDR: SM0 0xC0001038\n"
	"AND_SM_VAL: SM0 0xFFCAFFFF\n"
	"OR_SM_VAL: SM0 0x00150000\n"
	"STORE_SM_ADDR: SM0 0xC0001038\n"
	"LOAD_SM_ADDR: SM0 0xC0001038\n"
	"AND_SM_VAL: SM0 0xC0FFFFFF\n"
	"OR_SM_VAL: SM0 0x32000000\n"
	"STORE_SM_ADDR: SM0 0xC0001038\n"
	"LOAD_SM_ADDR: SM0 0xC0001038\n"
	"AND_SM_VAL: SM0 0x3FFFFFFF\n"
	"OR_SM_VAL: SM0 0x40000000\n"
	"STORE_SM_ADDR: SM0 0xC0001038\n"
	"DELAY: 0x00000001\n"
	"\n"
	";Step 17: Set default value for DRAM DQ VREF\n"
	"OR_VAL: 0xC0000308 0x00000010\n"
	"OR_VAL: 0xC000030C 0x00800001\n"
	"WRITE: 0xC0000028 0x13004000\n"
	"LOAD_SM_ADDR: SM0 0xC000030C\n"
	"DELAY: 0x00000001\n"
	"AND_SM_VAL: SM0 0xFFC0FFFF\n"
	"OR_SM_VAL: SM0 0x250000\n"
	"STORE_SM_ADDR: SM0 0xC000030C\n"
	"WRITE: 0xC0000028 0x13004000\n"
	"DELAY: 0x00000001\n"
	"AND_VAL: 0xC0000308 0xFFFFFFEF\n"
	"WRITE: 0xC0000028 0x13004000\n"
	"DELAY: 0x00000001\n"
	"\n"
	";Step18: Trigger DDR init for both CS\n"
	"WRITE: 0xC0000020 0x13000001\n"
	"\n"
	";Step19: Poll and wait for ddr init done\n"
	"WAIT_FOR_BIT_SET: 0xC0000008 0x00000001 0x00001000\n"
	"WAIT_FOR_BIT_SET: 0xC0000008 0x00000010 0x00001000\n"
	"; DDR INIT DONE\n"
	"\n"
	"LOAD_SM_VAL: SM0 0\n"
	"\n"
	"LABEL: LP1\n"
	"LOAD_SM_ADDR: SM2 0xC000030C\n"
	"AND_SM_VAL: SM2 0xFFC0FFFF\n"
	"MOV_SM_SM: SM1 SM0\n"
	"LSHIFT_SM_VAL: SM1 0x10\n"
	"OR_SM_SM: SM2 SM1\n"
	"STORE_SM_ADDR: SM2 0xC000030C\n"
	"OR_VAL: 0xC0000028 0x13004000\n"
	"ADD_SM_VAL: SM0 0x1\n"
	"TEST_SM_AND_BRANCH: SM0 0x000000FF 0x00000032 < LP1\n"
	"\n"
	"AND_VAL: 0xC0000308 0xFFFFFFEF\n"
	"OR_VAL: 0xC0000028 0x13004000\n"
	"OR_VAL: 0xC0000308 0x00000010\n"
	"OR_VAL: 0xC000030C 0x00800001\n"
	"WRITE: 0xC0000028 0x13004000\n"
	"DELAY: 0x00000001\n"
	"\n"
	"LOAD_SM_ADDR: SM2 0xC000030C\n"
	"AND_SM_VAL: SM2 0xFFC0FFFF\n"
	"OR_SM_VAL: SM2 0x00250000\n"
	"STORE_SM_ADDR: SM2 0xC000030C\n"
	"WRITE: 0xC0000028 0x13004000\n"
	"DELAY: 0x00000001\n"
	"\n"
	"AND_VAL: 0xC0000308 0xFFFFFFEF\n"
	"WRITE: 0xC0000028 0x13004000\n"
	"DELAY: 0x00000001\n"
};
