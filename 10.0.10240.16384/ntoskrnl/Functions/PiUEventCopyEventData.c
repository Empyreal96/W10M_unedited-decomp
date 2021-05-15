// PiUEventCopyEventData 
 
int __fastcall PiUEventCopyEventData(int a1, unsigned int a2, int a3, int a4)
{
  _DWORD *v5; // r10
  int v6; // r3
  int v7; // r4
  int v8; // r5
  int v9; // r3
  int v10; // r8
  int v11; // r7
  unsigned int v12; // r6
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r0
  char *v18; // r2
  unsigned int v19; // r7
  unsigned int v20; // r10
  int v21; // r1
  int v22; // r3
  int v23; // r4
  int v24; // [sp+0h] [bp-28h] BYREF
  unsigned int v25; // [sp+4h] [bp-24h]
  int v26; // [sp+8h] [bp-20h]

  v26 = a4;
  v24 = 0;
  v25 = a2;
  if ( a2 < 0x40 || *(_DWORD *)(a3 + 36) > a2 )
    return -1073741789;
  v5 = (_DWORD *)(a3 + 36);
  *(_BYTE *)(a1 + 4) = *(_BYTE *)(a3 + 40);
  *(_BYTE *)(a1 + 5) = *(_BYTE *)(a3 + 41);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a3 + 60);
  v6 = *(_DWORD *)(a3 + 48);
  v7 = *(_DWORD *)(a3 + 52);
  v8 = *(_DWORD *)(a3 + 56);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a3 + 44);
  *(_DWORD *)(a1 + 16) = v6;
  *(_DWORD *)(a1 + 20) = v7;
  *(_DWORD *)(a1 + 24) = v8;
  v9 = *(_DWORD *)(a3 + 60);
  if ( v9 == 2 )
  {
    v10 = RtlStringCchLengthW((unsigned __int16 *)(a3 + 96), 0x7FFFu, &v24);
    if ( v10 >= 0 )
    {
      v11 = v24;
      v12 = 2 * (v24 + 27);
      if ( v25 >= v12 )
      {
        v13 = v5[12];
        v14 = v5[13];
        v15 = v5[14];
        *(_DWORD *)(a1 + 36) = v5[11];
        *(_DWORD *)(a1 + 40) = v13;
        *(_DWORD *)(a1 + 44) = v14;
        *(_DWORD *)(a1 + 48) = v15;
        v16 = memmove(a1 + 52, (int)(v5 + 15), 2 * (v11 + 1));
        v10 = CmSetDeviceInterfacePathFormat(v16, a1 + 52, 0);
        if ( v10 >= 0 )
        {
          *(_DWORD *)(a1 + 28) = 0;
          *(_DWORD *)a1 = v12;
        }
        return v10;
      }
      return -1073741789;
    }
    return v10;
  }
  if ( v9 == 3 )
  {
    v10 = RtlStringCchLengthW((unsigned __int16 *)(a3 + 84), 0xC8u, &v24);
    if ( v10 < 0 || !v24 )
      return v10;
    v18 = (char *)v5 + ((2 * (v24 + 1) + 71) & 0xFFFFFFFC);
    v19 = *((unsigned __int16 *)v18 + 5) - 28;
    v20 = *((unsigned __int16 *)v18 + 5) + 32;
    if ( v25 >= v20 )
    {
      v21 = *((_DWORD *)v18 + 4);
      v22 = *((_DWORD *)v18 + 5);
      v23 = *((_DWORD *)v18 + 6);
      *(_DWORD *)(a1 + 36) = *((_DWORD *)v18 + 3);
      *(_DWORD *)(a1 + 40) = v21;
      *(_DWORD *)(a1 + 44) = v22;
      *(_DWORD *)(a1 + 48) = v23;
      *(_DWORD *)(a1 + 52) = *((_DWORD *)v18 + 8);
      *(_DWORD *)(a1 + 56) = v19;
      memmove(a1 + 60, (int)(v18 + 36), v19);
      *(_DWORD *)(a1 + 28) = 1;
      *(_DWORD *)a1 = v20;
      return v10;
    }
    return -1073741789;
  }
  return sub_7C1748(a1, a2);
}
