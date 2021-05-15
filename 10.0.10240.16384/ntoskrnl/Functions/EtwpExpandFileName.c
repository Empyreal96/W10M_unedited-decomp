// EtwpExpandFileName 
 
int __fastcall EtwpExpandFileName(int a1, _DWORD *a2, int a3, unsigned __int16 *a4)
{
  int v5; // r5
  unsigned int v7; // r6
  int v8; // r8
  unsigned int v9; // r3
  int v10; // r3
  int v11; // r10
  int v12; // r4
  int v14; // r5
  unsigned __int16 *v15; // r0
  unsigned __int16 *v16; // r6
  int v17; // r0
  unsigned int v18; // r4
  unsigned int v19; // r0
  unsigned __int16 *v22; // [sp+18h] [bp-30h]
  unsigned __int16 v23; // [sp+20h] [bp-28h] BYREF
  int v24; // [sp+24h] [bp-24h]

  v5 = a1;
  RtlInitUnicodeString((unsigned int)&v23, L"%SystemRoot%");
  v7 = *(unsigned __int16 *)a2;
  v8 = v23;
  v9 = v7;
  if ( v7 > v23 )
    v9 = v23;
  v22 = (unsigned __int16 *)a2[1];
  if ( !RtlCompareUnicodeStrings(v22, v9 >> 1, v24, v23 >> 1, 1) )
  {
    v11 = 1;
    if ( v7 == v8 )
      return sub_7F0D30();
    v14 = (unsigned __int16)NtSystemRoot - v8 + v7 + 2;
    if ( v22[(v7 >> 1) - 1] == 92 )
      v14 += *a4;
    v10 = a3;
    goto LABEL_12;
  }
  v10 = a3;
  v11 = 0;
  if ( a3 || v5 )
  {
    v14 = v7 + 2;
LABEL_12:
    if ( v10 )
      v14 += 2 * wcslen(L".000");
    if ( !v11 && a1 )
      v14 += *a4;
    v15 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v14, 1350005829);
    v16 = v15;
    if ( !v15 )
      return -1073741801;
    if ( v11 )
    {
      if ( *(unsigned __int16 *)a2 == v8 )
        v17 = RtlStringCbPrintfW(v15, v14, (int)L"%ws%ws%ws%ws", dword_63282C);
      else
        v17 = RtlStringCbPrintfW(v15, v14, (int)L"%ws%ws%ws", dword_63282C);
    }
    else if ( a1 )
    {
      v17 = RtlStringCbPrintfW(v15, v14, (int)L"%ws%ws", a2[1]);
    }
    else
    {
      v17 = RtlStringCbPrintfW(v15, v14, (int)L"%ws", a2[1]);
    }
    v12 = v17;
    if ( a3 )
    {
      v18 = wcslen(v16);
      v19 = wcslen(v16);
      v12 = RtlStringCbPrintfW(&v16[v19], v14 - 2 * v18, (int)L".%03d", a3);
    }
    RtlFreeAnsiString(a2);
    RtlInitUnicodeString((unsigned int)a2, v16);
    return v12;
  }
  return 0;
}
