// ObInitProcess 
 
int __fastcall ObInitProcess(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  unsigned int *v8; // r4
  unsigned int *v9; // r5
  int v10; // r5
  unsigned int *v12; // r0
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int *v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int *v19; // [sp+8h] [bp-28h] BYREF
  _DWORD v20[8]; // [sp+10h] [bp-20h] BYREF

  if ( !a1 )
  {
    v8 = 0;
    v9 = (unsigned int *)ExCreateHandleTable(a2, 1);
    goto LABEL_3;
  }
  v12 = (unsigned int *)ObReferenceProcessHandleTable(a1);
  v8 = v12;
  if ( !v12 )
    return -1073741558;
  if ( ExDupHandleTable(a2, v12, a3, a4, &v19) >= 0 )
  {
    v9 = v19;
LABEL_3:
    if ( v9 )
    {
      *(_DWORD *)(a2 + 336) = v9;
      if ( SeAuditingWithTokenForSubcategory(123, 0) )
      {
        v20[0] = a2;
        v20[1] = a1;
        ExEnumHandleTable(v9, ObAuditInheritedHandleProcedure, v20, 0);
      }
      if ( v8 )
      {
        v13 = (unsigned int *)(a1 + 172);
        __pld((void *)(a1 + 172));
        v14 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v15 = __ldrex(v13);
        while ( v15 == v14 && __strex(v14 - 2, v13) );
        if ( v15 != v14 )
          ExfReleaseRundownProtection((unsigned __int8 *)v13);
      }
      v10 = 0;
    }
    else
    {
      *(_DWORD *)(a2 + 336) = 0;
      if ( v8 )
      {
        v16 = (unsigned int *)(a1 + 172);
        __pld((void *)(a1 + 172));
        v17 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v18 = __ldrex(v16);
        while ( v18 == v17 && __strex(v17 - 2, v16) );
        if ( v18 != v17 )
          ExfReleaseRundownProtection((unsigned __int8 *)v16);
      }
      v10 = -1073741670;
    }
    return v10;
  }
  return sub_7F4798();
}
