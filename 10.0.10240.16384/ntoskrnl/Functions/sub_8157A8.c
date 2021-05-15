// sub_8157A8 
 
void __fastcall sub_8157A8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int a9)
{
  int v9; // r4
  unsigned int v10; // r5
  char *v11; // r6
  unsigned int *v12; // r9
  int v13; // r10
  char *v14; // r0
  unsigned int v15; // r4
  int v16; // r0
  unsigned __int16 *v17; // r7

  if ( !v13 )
  {
    v14 = wcsstr(v11, (char *)L"partition");
    if ( v14 )
      *(_WORD *)v14 = 0;
    v15 = wcslen((unsigned __int16 *)v11) + 1;
    v16 = ExAllocatePoolWithTag(1, 2 * v15, 1263556947);
    v17 = (unsigned __int16 *)v16;
    if ( !v16 )
LABEL_8:
      JUMPOUT(0x7AAF54);
    memmove(v16, (int)v11, 2 * v15);
    ExFreePoolWithTag(v10);
    a9 = 0;
    v9 = SiTranslateSymbolicLink(v17, &a9);
    if ( v9 < 0 )
      JUMPOUT(0x7AAF8C);
    v10 = a9;
  }
  *v12 = v10;
  if ( v9 >= 0 )
    JUMPOUT(0x7AAF5E);
  goto LABEL_8;
}
