// DbgkForwardException 
 
int __fastcall DbgkForwardException(int a1, int a2, int a3)
{
  unsigned int v6; // r3
  int v7; // r8
  int v8; // r0
  int v9; // r4
  int v10; // r7
  int v12; // r0
  int v13; // r7
  int v14; // r0
  int v15[2]; // [sp+0h] [bp-D0h] BYREF
  int v16; // [sp+8h] [bp-C8h] BYREF
  int v17; // [sp+Ch] [bp-C4h]
  int v18; // [sp+20h] [bp-B0h]
  int v19; // [sp+24h] [bp-ACh]
  char v20[80]; // [sp+28h] [bp-A8h] BYREF
  BOOL v21; // [sp+78h] [bp-58h]

  if ( a3 )
  {
    v15[1] = 0;
    v15[0] = 1;
    PsSetProcessFaultInformation(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v15);
  }
  v16 = 7602268;
  v17 = 8;
  v18 = 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_DWORD *)(v6 + 116);
  if ( a2 )
  {
    if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 4) != 0 )
      v9 = 0;
    else
      v9 = *(_DWORD *)(v7 + 340);
    v10 = 0;
  }
  else
  {
    v8 = PsCaptureExceptionPort(*(_DWORD *)(v6 + 116));
    v17 = 7;
    v9 = v8;
    v10 = 1;
  }
  if ( !v9 && a2 )
    return 0;
  v12 = memmove((int)v20, a1, 0x50u);
  v21 = a3 == 0;
  if ( v10 )
  {
    if ( !v9 )
      return sub_7D6884(v12);
    v13 = DbgkpSendApiMessageLpc(&v16, v9, a2);
    ObfDereferenceObject(v9);
  }
  else
  {
    v13 = DbgkpSendApiMessage(v7, a2 != 0, &v16);
  }
  v14 = v19;
  if ( v13 < 0 )
    return 0;
  if ( v19 != -2147418111 )
    return v14 >= 0;
  if ( a2 )
    return 0;
  v14 = DbgkpSendErrorMessage(a1);
  return v14 >= 0;
}
