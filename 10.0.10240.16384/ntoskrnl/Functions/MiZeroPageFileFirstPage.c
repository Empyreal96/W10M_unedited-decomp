// MiZeroPageFileFirstPage 
 
int __fastcall MiZeroPageFileFirstPage(int a1)
{
  int v2; // r2
  int v3; // r4
  _DWORD v5[2]; // [sp+8h] [bp-50h] BYREF
  int v6; // [sp+10h] [bp-48h] BYREF
  char v7[16]; // [sp+18h] [bp-40h] BYREF
  int v8; // [sp+28h] [bp-30h] BYREF
  __int16 v9; // [sp+2Ch] [bp-2Ch]
  __int16 v10; // [sp+2Eh] [bp-2Ah]
  unsigned int v11; // [sp+34h] [bp-24h]
  int v12; // [sp+38h] [bp-20h]
  int v13; // [sp+3Ch] [bp-1Ch]
  int v14; // [sp+40h] [bp-18h]
  int v15; // [sp+44h] [bp-14h]

  v5[0] = 0;
  v5[1] = 0;
  v8 = 0;
  v9 = 32;
  v12 = 0;
  v14 = 0;
  v13 = 4096;
  v10 = 16386;
  v15 = dword_634900;
  KeInitializeEvent((int)v7, 0, 0);
  v3 = IoSynchronousPageWriteEx(a1, &v8, v5, (int)v7, 0, (int)&v6);
  if ( v3 >= 0 )
  {
    KeWaitForSingleObject((unsigned int)v7, 18, 0, 0, 0);
    v3 = v6;
  }
  if ( (v10 & 1) != 0 )
    MmUnmapLockedPages(v11, (int)&v8, v2);
  return v3;
}
