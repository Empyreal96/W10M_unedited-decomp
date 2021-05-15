// MiLoadUserSymbols 
 
unsigned int __fastcall MiLoadUserSymbols(int a1)
{
  int v2; // r6
  unsigned int result; // r0
  int v4; // r4
  char v5[40]; // [sp+8h] [bp-28h] BYREF

  v2 = MI_REFERENCE_CONTROL_AREA_FILE(a1);
  if ( !*(_WORD *)(v2 + 48) )
    return sub_81BC80();
  v4 = DbgUnicodeStringToAnsiString((int)v5, (unsigned __int16 *)(v2 + 48));
  result = MI_DEREFERENCE_CONTROL_AREA_FILE(a1, v2);
  if ( v4 == 1 )
    DbgLoadUserImageSymbols();
  return result;
}
