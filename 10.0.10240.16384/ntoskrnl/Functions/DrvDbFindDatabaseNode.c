// DrvDbFindDatabaseNode 
 
int __fastcall DrvDbFindDatabaseNode(int a1, unsigned __int16 *a2, unsigned __int16 **a3, int a4)
{
  int v6; // r5
  unsigned __int16 *i; // r4
  int *v8; // r6
  unsigned __int16 *v9; // t1
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  *a3 = 0;
  v6 = RtlInitUnicodeStringEx((int)v11, a2);
  if ( v6 >= 0 )
  {
    v6 = -1073741772;
    v9 = *(unsigned __int16 **)(a1 + 12);
    v8 = (int *)(a1 + 12);
    for ( i = v9; i != (unsigned __int16 *)v8; i = *(unsigned __int16 **)i )
    {
      if ( RtlEqualUnicodeString(i + 4, (unsigned __int16 *)v11, 1) )
      {
        v6 = 0;
        *a3 = i;
        return v6;
      }
    }
  }
  return v6;
}
