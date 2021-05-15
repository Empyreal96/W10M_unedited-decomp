// IopCheckListForCancelableIrp 
 
int __fastcall IopCheckListForCancelableIrp(unsigned int *a1, int a2, int a3, int a4, unsigned int *a5, _DWORD *a6)
{
  unsigned int *v6; // r5
  int v7; // r6

  v6 = a5;
  v7 = 1;
  *a6 = 0;
  if ( !a5 )
    v6 = (unsigned int *)*a1;
  while ( a1 != v6 )
  {
    if ( (v6[8] & 0xFFFFFFFC) == a2 && (!a3 || v6[6] == a3) )
    {
      if ( a4 )
        return sub_529C0C();
      if ( *((char *)v6 + 19) < *((char *)v6 + 18) + 2 && !*((_BYTE *)v6 + 20) )
      {
        v7 = 0;
        sub_456A04(v6 + 8, 1);
        *a6 = v6 - 4;
        return v7;
      }
      if ( (*(v6 - 2) & 0x10000) == 0 )
        v7 = 0;
    }
    v6 = (unsigned int *)*v6;
  }
  return v7;
}
