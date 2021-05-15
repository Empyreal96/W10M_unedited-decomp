// ExpWnfGenerateStateName 
 
int __fastcall ExpWnfGenerateStateName(__int64 *a1, int a2, char a3, int a4)
{
  unsigned __int64 v5; // kr00_8
  __int64 v6; // kr08_8
  __int64 v7; // kr10_8
  unsigned int v8; // r3
  unsigned int v9; // r3
  int v10; // r1
  __int64 v11; // kr18_8
  unsigned int v12; // r3

  if ( a2 != 3 && a2 != 2 )
    return sub_7E7554();
  do
  {
    __dmb(0xBu);
    do
    {
      v5 = __ldrexd(&ExpWnfRuntimeNameSequenceNumber);
      v6 = v5 + 1;
    }
    while ( __strexd(v5 + 1, &ExpWnfRuntimeNameSequenceNumber) );
    __dmb(0xBu);
  }
  while ( v5 == -1i64 );
  if ( (v6 & 0xFFE0000000000000ui64) != 0 )
    return -1073741823;
  v7 = *a1;
  v8 = *(_DWORD *)a1 & 0xFFFFFFF0 | 1;
  *(_DWORD *)a1 = v8;
  *((_DWORD *)a1 + 1) = HIDWORD(v7);
  v9 = v8 & 0xFFFFFFCF | (16 * (a2 & 3));
  v10 = *((_DWORD *)a1 + 1);
  *(_DWORD *)a1 = v9;
  *((_DWORD *)a1 + 1) = v10;
  *(_DWORD *)a1 = v9 & 0xFFFFFC3F | ((a3 & 0xF) << 6);
  *((_DWORD *)a1 + 1) = v10;
  v11 = *a1;
  v12 = *(_DWORD *)a1 & 0xFFFFFBFF | ((a4 != 0) << 10);
  *(_DWORD *)a1 = v12;
  *((_DWORD *)a1 + 1) = HIDWORD(v11);
  *(_DWORD *)a1 = v12 & 0x7FF | ((_DWORD)v6 << 11);
  *((_DWORD *)a1 + 1) = v6 >> 21;
  return 0;
}
