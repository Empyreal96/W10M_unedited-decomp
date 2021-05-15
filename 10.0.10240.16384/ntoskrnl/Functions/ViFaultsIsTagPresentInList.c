// ViFaultsIsTagPresentInList 
 
int __fastcall ViFaultsIsTagPresentInList(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int *v5; // r2
  unsigned int v6; // r1
  int v7; // r0
  int v8; // r5
  int v10; // [sp+0h] [bp-18h] BYREF
  int v11[5]; // [sp+4h] [bp-14h] BYREF

  v10 = a2;
  v11[0] = a3;
  v11[1] = a4;
  v4 = 0;
  v5 = (int *)ViFaultTagsList;
  if ( (int *)ViFaultTagsList != &ViFaultTagsList )
  {
    v10 = a1;
    do
    {
      v6 = 0;
      v7 = 0;
      v11[0] = v5[2];
      while ( 1 )
      {
        v8 = *((unsigned __int8 *)v11 + v7);
        if ( v8 == 42 )
          return 1;
        if ( v8 != 63 && (v6 != 3 || (*((_BYTE *)&v10 + v7) & 0x7F) != v8) && *((unsigned __int8 *)&v10 + v7) != v8 )
          break;
        ++v6;
        ++v7;
        if ( v6 >= 4 )
          return 1;
      }
      v5 = (int *)*v5;
    }
    while ( v5 != &ViFaultTagsList );
  }
  return v4;
}
