// EtwpGenerateFileName 
 
int __fastcall EtwpGenerateFileName(unsigned __int16 *a1, unsigned int *a2, _DWORD *a3)
{
  _WORD *v4; // r0
  unsigned __int16 *v8; // r5
  unsigned int v9; // r7
  unsigned int v10; // r7
  int v11; // r8
  unsigned __int16 *v12; // r0
  unsigned __int16 *v13; // r5

  v4 = (_WORD *)*((_DWORD *)a1 + 1);
  if ( !v4 )
    return -1073741776;
  v8 = wcschr(v4, 37);
  if ( !v8 || v8 != wcsrchr(*((unsigned __int16 **)a1 + 1), 37) || !wcsstr(*((char **)a1 + 1), (char *)L"%d") )
    return -1073741773;
  __dmb(0xBu);
  do
  {
    v9 = __ldrex(a2);
    v10 = v9 + 1;
  }
  while ( __strex(v10, a2) );
  __dmb(0xBu);
  v11 = a1[1];
  v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v11 + 64, 1350005829);
  v13 = v12;
  if ( !v12 )
    return -1073741801;
  if ( RtlStringCbPrintfW(v12, v11 + 64, *((_DWORD *)a1 + 1), v10)
    || !memcmp(*((_DWORD *)a1 + 1), (unsigned int)v13, *a1) )
  {
    ExFreePoolWithTag((unsigned int)v13);
    return -1073741776;
  }
  RtlFreeAnsiString(a3);
  RtlInitUnicodeString((unsigned int)a3, v13);
  return 0;
}
