// PopSqmThermalCriticalEvent 
 
int __fastcall PopSqmThermalCriticalEvent(int a1, unsigned int a2, int a3)
{
  int result; // r0
  int v7; // r4
  int v8; // r6
  unsigned int v9; // r7
  char v10; // r2
  unsigned __int16 *v11; // r1
  bool v12; // [sp+8h] [bp-D0h] BYREF
  bool v13; // [sp+9h] [bp-CFh] BYREF
  bool v14; // [sp+Ah] [bp-CEh] BYREF
  bool v15; // [sp+Bh] [bp-CDh] BYREF
  int v16; // [sp+Ch] [bp-CCh] BYREF
  unsigned int v17; // [sp+10h] [bp-C8h] BYREF
  unsigned int v18; // [sp+14h] [bp-C4h] BYREF
  _DWORD v19[36]; // [sp+18h] [bp-C0h] BYREF
  char v20[48]; // [sp+A8h] [bp-30h] BYREF

  result = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(a1 + 24));
  v7 = result;
  if ( result )
    v8 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
  else
    v8 = 0;
  if ( v8 )
  {
    v9 = *(_DWORD *)(a1 + 176);
    if ( (unsigned int)dword_6163C8 > 5 )
    {
      result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
      if ( result )
      {
        v10 = *(_BYTE *)(a1 + 33);
        v15 = *(_BYTE *)(a1 + 280) != 0;
        v11 = *(unsigned __int16 **)(v8 + 164);
        v14 = (v10 & 1) != 0;
        v13 = (v10 & 4) != 0;
        v12 = v9 > a2;
        v19[8] = &v15;
        v19[9] = 0;
        v19[10] = 1;
        v19[11] = 0;
        v19[12] = &v14;
        v19[13] = 0;
        v19[14] = 1;
        v19[15] = 0;
        v19[16] = &v13;
        v19[17] = 0;
        v19[18] = 1;
        v19[19] = 0;
        v19[20] = &v16;
        v19[21] = 0;
        v19[22] = 4;
        v19[23] = 0;
        v19[24] = &v18;
        v19[25] = 0;
        v19[26] = 4;
        v19[27] = 0;
        v19[28] = &v17;
        v19[29] = 0;
        v19[30] = 4;
        v19[31] = 0;
        v19[32] = &v12;
        v19[33] = 0;
        v19[34] = 1;
        v19[35] = 0;
        v16 = a3;
        v17 = a2;
        v18 = v9;
        TlgCreateWsz((int)v20, v11);
        result = TlgWrite(&dword_6163C8, (unsigned __int8 *)dword_41477C, 0, 0, 10, v19);
      }
    }
  }
  if ( v7 )
    result = ObfDereferenceObject(v7);
  return result;
}
