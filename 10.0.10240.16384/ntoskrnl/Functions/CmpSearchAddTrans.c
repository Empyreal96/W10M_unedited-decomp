// CmpSearchAddTrans 
 
int __fastcall CmpSearchAddTrans(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r4
  int result; // r0

  v7 = (unsigned __int8)CmpMiniNTBoot;
  *a7 = 0;
  if ( v7 )
    goto LABEL_5;
  if ( a5 )
    JUMPOUT(0x7FDD8A);
  if ( !a4 )
LABEL_5:
    result = 0;
  else
    result = sub_7FDD70();
  return result;
}
