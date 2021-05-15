// SepDuplicateClaimAttributes 
 
int __fastcall SepDuplicateClaimAttributes(unsigned int *a1, unsigned int **a2)
{
  int v2; // r4
  _DWORD *v3; // r7
  _DWORD *v4; // r8
  int *v5; // r9
  int v8; // r0
  int v9; // r1
  unsigned int *v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v15; // [sp+4h] [bp-44h]
  int v16; // [sp+8h] [bp-40h]
  int v17; // [sp+18h] [bp-30h] BYREF
  int v18; // [sp+1Ch] [bp-2Ch]
  int v19; // [sp+20h] [bp-28h]
  int v20[9]; // [sp+24h] [bp-24h] BYREF

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  v5 = 0;
  v20[0] = 0;
  if ( a2 )
  {
    *a2 = 0;
    if ( !a1 )
      return 0;
    v8 = AuthzBasepAllocateClaimCollectionNoLists();
    v10 = (unsigned int *)v8;
    if ( !v8 )
      return -1073741670;
    if ( a1[72] )
    {
      v4 = AuthzBasepAllocateSecurityAttributesList(v8, v9);
      if ( !v4 )
      {
        v2 = -1073741670;
LABEL_34:
        ExFreePoolWithTag((unsigned int)v10);
        return v2;
      }
      v8 = AuthzBasepDuplicateSecurityAttributes(a1[72], (int)v4, 0);
      v2 = v8;
      if ( v8 < 0 )
      {
LABEL_24:
        if ( v4 )
        {
          if ( v18 )
            AuthzBasepFreeSecurityAttributesList((int)v4);
          ExFreePoolWithTag((unsigned int)v4);
        }
        if ( v3 )
        {
          if ( v19 )
            AuthzBasepFreeSecurityAttributesList((int)v3);
          ExFreePoolWithTag((unsigned int)v3);
        }
        if ( v5 )
          ExFreePoolWithTag((unsigned int)v5);
        goto LABEL_34;
      }
      v18 = 1;
      v10[72] = (unsigned int)v4;
    }
    if ( a1[73] )
    {
      v3 = AuthzBasepAllocateSecurityAttributesList(v8, v9);
      if ( !v3 )
      {
LABEL_14:
        v2 = -1073741670;
        goto LABEL_24;
      }
      v2 = AuthzBasepDuplicateSecurityAttributes(a1[73], (int)v3, 0);
      if ( v2 < 0 )
        goto LABEL_24;
      v19 = 1;
      v10[73] = (unsigned int)v3;
    }
    v11 = a1[1];
    if ( v11 && *a1 )
    {
      v2 = SepLengthSidAndAttributesArray(v11, *a1, &v17);
      if ( v2 < 0 )
        goto LABEL_24;
      v12 = v17;
      v5 = (int *)ExAllocatePoolWithTag(1, v17, 1683252563);
      if ( !v5 )
        goto LABEL_14;
      v2 = SeCaptureSidAndAttributesArray(a1[1], *a1, 0, (int)v5, v12, v15, v16, v20, (unsigned int *)&v17);
      if ( v2 < 0 )
        goto LABEL_24;
      v13 = *a1;
      *v10 = *a1;
      v10[1] = (unsigned int)v5;
      RtlSidHashInitialize(v5, v13, (int)(v10 + 4));
    }
    *a2 = v10;
    if ( v2 >= 0 )
      return v2;
    goto LABEL_24;
  }
  return -1073741811;
}
