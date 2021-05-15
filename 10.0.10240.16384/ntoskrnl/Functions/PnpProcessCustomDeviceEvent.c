// PnpProcessCustomDeviceEvent 
 
int __fastcall PnpProcessCustomDeviceEvent(int *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, char a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, char a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  int v68; // r7
  __int64 v69; // kr00_8
  int v70; // r1
  int v71; // r2
  int v72; // r3

  v68 = *a1;
  v69 = *(_QWORD *)(*a1 + 96);
  if ( !memcmp(HIDWORD(v69) + 4, (unsigned int)&GUID_TARGET_DEVICE_TRANSPORT_RELATIONS_CHANGED, 16) )
    return sub_7C0C18(
             0,
             v70,
             v71,
             v72,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             a16,
             a17,
             a18,
             a19,
             a20,
             a21,
             a22,
             a23,
             a24,
             a25,
             a26,
             a27,
             a28,
             a29,
             a30,
             a31,
             a32,
             a33,
             a34,
             a35,
             a36,
             a37,
             a38,
             a39,
             a40,
             a41,
             a42,
             a43,
             a44,
             a45,
             a46,
             a47,
             a48,
             a49,
             a50,
             a51,
             a52,
             a53,
             a54,
             a55,
             a56,
             a57,
             a58,
             a59,
             a60,
             a61,
             a62,
             a63,
             a64,
             a65,
             a66,
             a67,
             a68,
             STACK[0x284]);
  PiUEventNotifyUserMode(v68);
  PnpNotifyTargetDeviceChange(HIDWORD(v69) + 4, v69, HIDWORD(v69), 0);
  return 0;
}
