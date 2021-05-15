// ExpWnfGetPermanentDataStoreHandle 
 
int __fastcall ExpWnfGetPermanentDataStoreHandle(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  unsigned int *v5; // r4
  unsigned int v6; // r3
  int result; // r0
  unsigned int v8; // r1
  unsigned int v9; // [sp+8h] [bp-10h]

  v9 = (unsigned int)a4;
  if ( a2 == 3 || a2 == 2 )
    v5 = a1 + 10;
  else
    v5 = a1 + 9;
  v6 = *v5;
  if ( *v5 )
  {
LABEL_5:
    result = 0;
    *a4 = v6;
    return result;
  }
  result = ExpWnfGetPermanentDataStoreHandleByScopeId(a1[2]);
  if ( result >= 0 )
  {
    __dmb(0xBu);
    do
      v8 = __ldrex(v5);
    while ( !v8 && __strex(v9, v5) );
    __dmb(0xBu);
    if ( v8 )
      return sub_81881C();
    v6 = *v5;
    goto LABEL_5;
  }
  return result;
}
