// SiTranslateSymbolicLink 
 
int __fastcall SiTranslateSymbolicLink(unsigned __int16 *a1, _DWORD *a2)
{
  int v3; // r4
  __int16 v4; // r6
  int v5; // r0
  unsigned __int16 v7; // [sp+8h] [bp-48h] BYREF
  __int16 v8; // [sp+Ah] [bp-46h]
  int v9; // [sp+Ch] [bp-44h]
  char v10[8]; // [sp+10h] [bp-40h] BYREF
  int v11; // [sp+18h] [bp-38h]
  int v12; // [sp+1Ch] [bp-34h]
  unsigned __int16 *v13; // [sp+20h] [bp-30h]
  int v14; // [sp+24h] [bp-2Ch]
  int v15; // [sp+28h] [bp-28h]
  int v16; // [sp+2Ch] [bp-24h]

  v9 = 0;
  RtlInitUnicodeString((unsigned int)v10, a1);
  v11 = 24;
  v12 = 0;
  v13 = (unsigned __int16 *)v10;
  v15 = 0;
  v16 = 0;
  v14 = 576;
  v3 = ZwOpenSymbolicLinkObject();
  if ( v3 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)&v7, 0);
    v4 = 0;
    do
    {
      while ( 1 )
      {
        v3 = ZwQuerySymbolicLinkObject();
        if ( v3 == -1073741789 )
          break;
        ZwClose();
        if ( v3 < 0 )
        {
          v5 = v9;
          goto LABEL_14;
        }
        *(_WORD *)(v9 + 2 * (v7 >> 1)) = 0;
        v11 = 24;
        v12 = 0;
        v13 = &v7;
        v15 = 0;
        v16 = 0;
        v8 = v4;
        v14 = 576;
        if ( ZwOpenSymbolicLinkObject() < 0 )
        {
          v5 = v9;
          v3 = 0;
          *a2 = v9;
          goto LABEL_7;
        }
      }
      if ( v9 )
        return sub_815928();
      v4 = 2;
      v8 = 0;
      v5 = ExAllocatePoolWithTag(1, 2, 1263556947);
      v9 = v5;
    }
    while ( v5 );
    v3 = -1073741670;
LABEL_7:
    if ( v3 >= 0 )
      return v3;
LABEL_14:
    if ( v5 )
      ExFreePoolWithTag(v5);
  }
  return v3;
}
