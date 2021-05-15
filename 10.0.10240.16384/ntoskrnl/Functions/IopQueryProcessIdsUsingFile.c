// IopQueryProcessIdsUsingFile 
 
int __fastcall IopQueryProcessIdsUsingFile(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  _DWORD *v5; // r9
  unsigned int v6; // r8
  int i; // r0
  int *v8; // r0
  int *v9; // r5
  int v10; // r0
  unsigned int *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v14; // r3
  int v15; // r6
  unsigned int v17; // [sp+0h] [bp-50h]
  int v20; // [sp+18h] [bp-38h]
  int v21; // [sp+28h] [bp-28h] BYREF
  bool v22; // [sp+2Ch] [bp-24h]
  int varg_r0; // [sp+58h] [bp+8h]
  _DWORD *varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  _DWORD *varg_r3; // [sp+64h] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  varg_r0 = a1;
  v5 = a2 + 1;
  v17 = (unsigned int)(a3 - 4) >> 2;
  v6 = 0;
  *a2 = 0;
  v21 = a1;
  for ( i = 0; ; i = (int)v9 )
  {
    v8 = PsGetNextProcess(i);
    v9 = v8;
    if ( !v8 )
      break;
    v10 = ObReferenceProcessHandleTable((int)v8);
    if ( v10 )
    {
      v22 = v9 == *(int **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v20 = ExEnumHandleTable(v10, IopIsFileOpenOrSection, &v21, 0);
      v11 = (unsigned int *)(v9 + 43);
      __pld(v9 + 43);
      v12 = v9[43] & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v13 = __ldrex(v11);
      while ( v13 == v12 && __strex(v12 - 2, v11) );
      if ( v13 != v12 )
        ExfReleaseRundownProtection((unsigned __int8 *)v11);
      v14 = v20;
    }
    else
    {
      v14 = 0;
    }
    if ( v14 || MmIsFileMapped(v9, a1) )
    {
      if ( v6 < v17 )
      {
        *v5 = v9[44];
        ++*a2;
        ++v5;
      }
      ++v6;
    }
  }
  *a4 = 4 * (v6 + 1);
  if ( v6 <= v17 )
    v15 = 0;
  else
    v15 = -1073741820;
  return v15;
}
