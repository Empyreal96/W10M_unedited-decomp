// IoAllocateMdl 
 
int __fastcall IoAllocateMdl(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r6
  unsigned int v6; // r9
  __int16 v9; // r8
  _DWORD *v10; // r4
  int v11; // r7
  int result; // r0
  int v13; // r7
  __int64 v14; // kr00_8
  int v15; // r0
  int v16; // r1
  int *i; // r2

  v5 = a1 & 0xFFF;
  v6 = (unsigned int)(v5 + a2 + 4095) >> 12;
  v9 = 0;
  if ( v6 > 0x11 )
  {
    v16 = 4 * (v6 + 7);
  }
  else
  {
    v9 = 8;
    v10 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
    v11 = v10[710];
    ++*(_DWORD *)(v11 + 12);
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)v11);
    if ( result )
      goto LABEL_3;
    ++*(_DWORD *)(v11 + 16);
    v13 = v10[711];
    ++*(_DWORD *)(v13 + 12);
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)v13);
    if ( result
      || (v14 = *(_QWORD *)(v13 + 32),
          v15 = *(_DWORD *)(v13 + 28),
          ++*(_DWORD *)(v13 + 16),
          (result = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v13 + 40))(v15, HIDWORD(v14), v14)) != 0) )
    {
LABEL_3:
      *(_DWORD *)result = v10[357];
      goto LABEL_4;
    }
    v16 = 96;
  }
  result = ExAllocatePoolWithTag(512, v16, 543974477);
  if ( !result )
    return 0;
LABEL_4:
  *(_DWORD *)result = 0;
  *(_WORD *)(result + 4) = 4 * (v6 + 7);
  *(_DWORD *)(result + 16) = a1 & 0xFFFFF000;
  *(_DWORD *)(result + 20) = a2;
  *(_DWORD *)(result + 24) = v5;
  *(_WORD *)(result + 6) = v9;
  if ( a5 )
  {
    if ( a3 )
    {
      for ( i = *(int **)(a5 + 4); *i; i = (int *)*i )
        ;
      *i = result;
    }
    else
    {
      *(_DWORD *)(a5 + 4) = result;
    }
  }
  return result;
}
