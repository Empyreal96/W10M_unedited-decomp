// MiReadWriteVirtualMemory 
 
int __fastcall MiReadWriteVirtualMemory(int a1, unsigned int a2, unsigned int a3, int a4, unsigned int a5, int a6)
{
  int v9; // r2
  unsigned int v10; // r3
  _DWORD *v11; // r4
  _DWORD *v12; // r2
  int v13; // r5
  int v14; // r6
  int v15; // r0
  int v16; // r6
  int v17; // r0
  int v19; // [sp+14h] [bp-34h]
  int v20; // [sp+1Ch] [bp-2Ch] BYREF
  unsigned int v21; // [sp+20h] [bp-28h]
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[14] = a4;
  _24[13] = a3;
  _24[12] = a2;
  _24[11] = a1;
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  _24[0] = v21;
  v9 = *(char *)(v21 + 0x15A);
  v19 = v9;
  if ( *(_BYTE *)(v21 + 0x15A) )
  {
    v10 = a2 + a4;
    if ( a2 + a4 < a2 || a3 + a4 < a3 || v10 > MmHighestUserAddress || a3 + a4 > MmHighestUserAddress )
      return -1073741819;
    v11 = (_DWORD *)a5;
    if ( a5 )
    {
      v12 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v12 = (_DWORD *)MmUserProbeAddress;
      *v12 = *v12;
      v9 = v19;
    }
    else
    {
      v9 = *(char *)(v21 + 0x15A);
    }
  }
  else
  {
    v11 = (_DWORD *)a5;
  }
  v14 = 0;
  v20 = 0;
  v13 = 0;
  if ( a4 )
  {
    v13 = ObReferenceObjectByHandleWithTag(a1, a6, PsProcessType, v9, 1834380621, _24, 0);
    if ( v13 >= 0 )
    {
      v15 = *(_DWORD *)(v21 + 116);
      v16 = _24[0];
      if ( a6 == 16 )
        v17 = MmCopyVirtualMemory(_24[0], a2, v15, a3, a4, v19, &v20);
      else
        v17 = MmCopyVirtualMemory(v15, a3, _24[0], a2, a4, v19, &v20);
      v13 = v17;
      ObfDereferenceObjectWithTag(v16);
      v14 = v20;
    }
  }
  if ( v11 )
    *v11 = v14;
  return v13;
}
