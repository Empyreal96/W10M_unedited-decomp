// EtwpBuildNotificationPacket 
 
int __fastcall EtwpBuildNotificationPacket(int a1, int a2, int a3, _DWORD *a4)
{
  int v7; // r0
  int v8; // r8
  int v10; // r4
  _DWORD *v11; // r7
  int v12; // r1
  _DWORD *v13; // [sp+0h] [bp-28h] BYREF
  int v14; // [sp+4h] [bp-24h]
  _DWORD *v15; // [sp+8h] [bp-20h]

  v13 = (_DWORD *)a2;
  v15 = a4;
  v14 = a1;
  v7 = EtwpGetSchematizedFilterSize(a1);
  v8 = v7;
  if ( v7 )
  {
    v10 = EtwpAllocDataBlock(v7 + 136, 0, &v13);
    if ( v10 >= 0 )
    {
      v11 = v13;
      if ( a2 )
        memmove((int)v13, a2, 0x78u);
      v11[29] = 1;
      v11[1] = v8 + 136;
      v11[2] = 1;
      v11[32] = v8;
      v11[33] = 0x80000000;
      v11[30] = 136;
      v11[31] = 0;
      v12 = v14;
      *a4 = v11;
      EtwpCopySchematizedFilters(v11 + 34, v12, a3);
    }
  }
  else
  {
    if ( !a2 )
      return sub_807A94();
    v10 = EtwpAllocDataBlock(*(_DWORD *)(a2 + 4), a2, a4);
  }
  return v10;
}
