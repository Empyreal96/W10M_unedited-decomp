// EtwpCreateNtFileName 
 
int __fastcall EtwpCreateNtFileName(unsigned __int16 *a1, unsigned int *a2, _DWORD *a3)
{
  unsigned int v6; // r0
  unsigned int v7; // r5
  int result; // r0
  __int16 *v9; // r0
  unsigned int v10; // r0
  int v11; // r8
  _WORD *v12; // r0
  unsigned int v13; // r6
  const __int16 *v14; // r3

  v6 = wcslen(a1);
  if ( !(2 * v6) )
    return -1073741773;
  v7 = 2 * v6 + 2;
  if ( v7 > 0xA && *a1 == 92 )
    return sub_80ADAC();
  if ( *a1 == 92 && a1[1] == 92 )
    v9 = L"\\??\\UNC";
  else
    v9 = L"\\DosDevices\\";
  v10 = wcslen((unsigned __int16 *)v9);
  *a3 = 2 * v10;
  v11 = 2 * v10;
  v12 = (_WORD *)ExAllocatePoolWithTag(1, 2 * v10 + v7, 1350005829);
  v13 = (unsigned int)v12;
  if ( v12 )
  {
    if ( *a1 == 92 && a1[1] == 92 )
      v14 = L"\\??\\UNC";
    else
      v14 = L"\\DosDevices\\";
    if ( !RtlStringCbPrintfW(v12, v11 + v7, (int)L"%ws%ws", (int)v14) )
    {
      *a2 = v13;
      return 0;
    }
    ExFreePoolWithTag(v13);
    result = -1073741811;
  }
  else
  {
    result = -1073741801;
  }
  *a2 = 0;
  return result;
}
