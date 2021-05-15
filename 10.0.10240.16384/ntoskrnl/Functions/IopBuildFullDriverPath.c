// IopBuildFullDriverPath 
 
int __fastcall IopBuildFullDriverPath(unsigned __int16 *a1, int a2, unsigned __int16 *a3)
{
  unsigned int v4; // r8
  unsigned int v5; // r10
  int v7; // r0
  const __int16 *v8; // r6
  int v9; // r3
  unsigned int v10; // r4
  _WORD *v11; // r9
  const __int16 *v12; // r7
  unsigned int v13; // r3
  unsigned int v14; // r1
  int v16; // r0
  int v17; // r4
  int v18; // r3
  const __int16 *v19; // [sp+0h] [bp-20h] BYREF

  a3[1] = 0;
  *a3 = 0;
  *((_DWORD *)a3 + 1) = 0;
  v4 = 0;
  v5 = 0;
  v19 = 0;
  v7 = IopGetRegistryValue(a2, L"ImagePath", 60, &v19);
  v8 = v19;
  if ( v7 >= 0 && (v9 = *((_DWORD *)v19 + 3)) != 0 )
  {
    v10 = v9 - 2;
    v11 = (_WORD *)((char *)v19 + *((_DWORD *)v19 + 2));
    if ( *v11 == 92 )
    {
      v12 = 0;
    }
    else
    {
      v12 = L"\\SystemRoot\\";
      v4 = 24;
    }
    v19 = 0;
  }
  else
  {
    v10 = *a1;
    v11 = (_WORD *)*((_DWORD *)a1 + 1);
    v12 = L"\\SystemRoot\\System32\\Drivers\\";
    v19 = L".SYS";
    v4 = 58;
    v5 = 8;
  }
  v13 = v4 + v10 + v5 + 2;
  v14 = (unsigned __int16)v13;
  a3[1] = v13;
  if ( (unsigned __int16)v13 < v13 )
    return sub_7CA5DC();
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v18 = 40;
    else
      v18 = 32;
    v16 = ExAllocatePoolWithTagPriority(1, v14, 538996553, v18);
  }
  else
  {
    v16 = ExAllocatePoolWithTag(1, (unsigned __int16)v13, 538996553);
  }
  *((_DWORD *)a3 + 1) = v16;
  if ( v16 )
  {
    *a3 = a3[1] - 2;
    if ( v12 )
      memmove(v16, (int)v12, v4);
    if ( v10 )
      memmove(*((_DWORD *)a3 + 1) + v4, (int)v11, v10);
    if ( v5 )
      memmove(*((_DWORD *)a3 + 1) + v4 + v10, (int)v19, v5);
    v17 = 0;
    *(_WORD *)(*((_DWORD *)a3 + 1) + 2 * (*a3 >> 1)) = 0;
  }
  else
  {
    v17 = -1073741670;
    a3[1] = 0;
  }
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return v17;
}
