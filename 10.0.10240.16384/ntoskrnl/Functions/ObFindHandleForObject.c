// ObFindHandleForObject 
 
int __fastcall ObFindHandleForObject(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r5
  int v10; // r0
  unsigned int *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v15; // [sp+0h] [bp-20h] BYREF
  int v16; // [sp+4h] [bp-1Ch]
  int v17; // [sp+8h] [bp-18h]

  v15 = a2;
  v16 = a3;
  v17 = a4;
  v9 = 0;
  v10 = ObReferenceProcessHandleTable(a1);
  if ( v10 )
  {
    if ( a2 )
      v15 = a2 - 24;
    else
      v15 = 0;
    v16 = a3;
    v17 = a4;
    if ( ExEnumHandleTable(v10, ObpEnumFindHandleProcedure, &v15, a5) )
      v9 = 1;
    v11 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v12 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v13 = __ldrex(v11);
    while ( v13 == v12 && __strex(v12 - 2, v11) );
    if ( v13 != v12 )
      ExfReleaseRundownProtection((unsigned __int8 *)v11);
  }
  return v9;
}
