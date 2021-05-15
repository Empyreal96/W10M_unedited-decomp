// IopExecuteHardwareProfileChange 
 
int __fastcall IopExecuteHardwareProfileChange(int a1, unsigned __int16 **a2, unsigned int a3, int a4, _BYTE *a5)
{
  int v7; // r9
  int v8; // r0
  unsigned int v9; // r10
  int v10; // r4
  unsigned int v11; // r4
  unsigned int v12; // r5
  unsigned __int16 *v13; // t1
  unsigned int v14; // r5
  unsigned int v15; // r4
  unsigned int v16; // r7
  __int64 v17; // kr00_8
  int v18; // r2
  int v19; // r7
  unsigned __int16 *v20; // r2
  unsigned int v21; // r1
  int v22; // t1
  int v23; // r7
  int v24; // r0
  int v25; // r2
  unsigned __int16 *v26; // r5
  _WORD *v27; // r8
  unsigned __int16 *v28; // r9
  unsigned int v29; // r10
  unsigned int v30; // r4
  __int16 v31; // r3
  int v33; // [sp+8h] [bp-28h]

  v7 = a4;
  v8 = ExAllocatePoolWithTag(512, 8 * a3, 863006288);
  v9 = v8;
  v33 = v8;
  if ( !v8 )
    return -1073741670;
  if ( a3 )
  {
    v11 = v8;
    v12 = a3;
    do
    {
      v13 = *a2++;
      RtlInitUnicodeString(v11, v13);
      v11 += 8;
      --v12;
    }
    while ( v12 );
    v14 = a3;
    do
    {
      if ( a3 != 1 )
      {
        v15 = v9;
        v16 = a3 - 1;
        do
        {
          if ( (int)RtlCompareUnicodeString((unsigned __int16 *)v15, (unsigned __int16 *)(v15 + 8), 0) > 0 )
          {
            v17 = *(_QWORD *)(v15 + 4);
            v18 = *(_DWORD *)v15;
            *(_DWORD *)v15 = HIDWORD(v17);
            *(_DWORD *)(v15 + 4) = *(_DWORD *)(v15 + 12);
            *(_DWORD *)(v15 + 8) = v18;
            *(_DWORD *)(v15 + 12) = v17;
          }
          v15 += 8;
          --v16;
        }
        while ( v16 );
      }
      --v14;
    }
    while ( v14 );
  }
  v19 = 0;
  if ( a3 )
  {
    v20 = (unsigned __int16 *)v9;
    v21 = a3;
    do
    {
      v22 = *v20;
      v20 += 4;
      v19 += v22;
      --v21;
    }
    while ( v21 );
  }
  v23 = v19 + 2;
  v24 = ExAllocatePoolWithTag(512, v23 + 6, 863006288);
  v26 = (unsigned __int16 *)v24;
  if ( v24 )
  {
    v27 = (_WORD *)(v24 + 4);
    if ( a3 )
    {
      v28 = (unsigned __int16 *)v9;
      v29 = a3;
      do
      {
        v30 = *v28;
        memmove((int)v27, *((_DWORD *)v28 + 1), v30);
        v27 = (_WORD *)((char *)v27 + v30);
        v28 += 4;
        --v29;
      }
      while ( v29 );
      v9 = v33;
      v7 = a4;
    }
    *v27 = 0;
    v26[1] = v23;
    if ( a3 > 1 || v26[2] )
      v31 = 2;
    else
      v31 = 1;
    *v26 = v31;
    v10 = CmSetAcpiHwProfile(
            v26,
            (int (__fastcall *)(unsigned int, int *, _DWORD))IopExecuteHwpDefaultSelect,
            v25,
            v7,
            a5);
  }
  else
  {
    v10 = -1073741670;
  }
  ExFreePoolWithTag(v9);
  if ( v26 )
    ExFreePoolWithTag((unsigned int)v26);
  return v10;
}
