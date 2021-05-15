// ObGetProcessHandleCount 
 
int __fastcall ObGetProcessHandleCount(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  unsigned int *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1
  int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v6 = ObReferenceProcessHandleTable(a1);
  if ( !v6 )
    return sub_7F6A44();
  ExHandleTableQuery(v6, v11, a2);
  v8 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v9 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v10 = __ldrex(v8);
  while ( v10 == v9 && __strex(v9 - 2, v8) );
  if ( v10 != v9 )
    ExfReleaseRundownProtection((unsigned __int8 *)v8);
  return v11[0];
}
