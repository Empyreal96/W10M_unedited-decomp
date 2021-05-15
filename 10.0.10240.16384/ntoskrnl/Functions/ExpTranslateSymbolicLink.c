// ExpTranslateSymbolicLink 
 
int __fastcall ExpTranslateSymbolicLink(unsigned __int16 *a1, _DWORD *a2)
{
  unsigned __int16 *v3; // r5
  __int16 v4; // r7
  int v5; // r4
  int v7; // [sp+4h] [bp-4Ch]
  int v8; // [sp+8h] [bp-48h]
  char v9[8]; // [sp+10h] [bp-40h] BYREF
  int v10; // [sp+18h] [bp-38h]
  int v11; // [sp+1Ch] [bp-34h]
  char *v12; // [sp+20h] [bp-30h]
  int v13; // [sp+24h] [bp-2Ch]
  int v14; // [sp+28h] [bp-28h]
  int v15; // [sp+2Ch] [bp-24h]

  v3 = 0;
  v4 = 2;
  RtlInitUnicodeString((unsigned int)v9, a1);
  v10 = 24;
  v11 = 0;
  v12 = v9;
  v14 = 0;
  v15 = 0;
  v13 = 576;
  v5 = ZwOpenSymbolicLinkObject();
  if ( v5 >= 0 )
  {
    while ( 2 )
    {
      for ( LOWORD(v8) = 0; ; LOWORD(v8) = 0 )
      {
        v5 = ZwQuerySymbolicLinkObject();
        if ( v5 != -1073741789 )
          break;
        if ( v3 )
          return sub_8154C0();
        v4 = v7 + 2;
        v3 = (unsigned __int16 *)ExAllocatePoolWithTag(512, v7 + 2, 1920364101);
        if ( !v3 )
        {
          ZwClose();
          return -1073741670;
        }
      }
      ZwClose();
      if ( v5 < 0 )
      {
        if ( v3 )
          ExFreePoolWithTag((unsigned int)v3);
      }
      else
      {
        *v3 = 0;
        HIWORD(v8) = v4;
        RtlInitUnicodeString((unsigned int)v9, v3);
        v10 = 24;
        v11 = 0;
        v12 = v9;
        v13 = 576;
        v14 = 0;
        v15 = 0;
        if ( ZwOpenSymbolicLinkObject() >= 0 )
          continue;
        v5 = 0;
        *a2 = v8;
        a2[1] = v3;
      }
      break;
    }
  }
  return v5;
}
