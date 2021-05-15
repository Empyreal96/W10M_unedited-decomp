// PsInitializeFullProcessImageName 
 
int __fastcall PsInitializeFullProcessImageName(int a1)
{
  int *v1; // r5
  int v3; // r4
  int v4; // r6
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v9; // r0
  int *v10; // r0
  unsigned int v11; // [sp+8h] [bp-130h] BYREF
  int v12; // [sp+Ch] [bp-12Ch] BYREF
  int v13; // [sp+10h] [bp-128h] BYREF
  int v14; // [sp+14h] [bp-124h]

  v12 = 0;
  v1 = 0;
  if ( (*(_DWORD *)(a1 + 736) & 1) != 0 )
  {
LABEL_20:
    v11 = 8;
    v10 = (int *)ExAllocatePoolWithTag(512, 8, 1850307408);
    v1 = v10;
    if ( v10 )
    {
      memset(v10, 0, v11);
      v3 = 0;
    }
    else
    {
      v3 = -1073741801;
    }
LABEL_13:
    *(_DWORD *)(a1 + 380) = v1;
    return v3;
  }
  v3 = PsReferenceProcessFilePointer(a1, &v12);
  v4 = v12;
  if ( v3 < 0 )
  {
LABEL_10:
    if ( v4 )
      ObfDereferenceObject(v4);
    if ( v3 >= 0 )
      goto LABEL_13;
    goto LABEL_20;
  }
  v1 = &v13;
  v11 = 264;
  v5 = ObQueryNameStringMode(v12, (int)&v13, 264, &v11, 0);
  v3 = v5;
  if ( v5 != -2147483643 && v5 != -1073741789 && v5 != -1073741820 )
  {
    if ( v5 < 0 )
      goto LABEL_10;
    if ( v11 - 9 <= 0xFF )
    {
      v6 = ExAllocatePoolWithTag(512, v11, 1850307408);
      v1 = (int *)v6;
      if ( v6 )
      {
        v7 = v6 + 8;
        *v1 = v13;
        v1[1] = v14;
        v1[1] = v7;
        memmove(v7, v14, HIWORD(v13));
        goto LABEL_10;
      }
      goto LABEL_19;
    }
LABEL_18:
    v3 = -1073741637;
    goto LABEL_10;
  }
  if ( v11 <= 0x108 )
    goto LABEL_18;
  v9 = ExAllocatePoolWithTag(512, v11, 1850307408);
  v1 = (int *)v9;
  if ( !v9 )
  {
LABEL_19:
    v3 = -1073741801;
    goto LABEL_10;
  }
  v3 = ObQueryNameStringMode(v4, v9, v11, &v11, 0);
  if ( v3 >= 0 )
    goto LABEL_10;
  return sub_7F64A8();
}
