// IopSymlinkQueryEnabledClasses 
 
int __fastcall IopSymlinkQueryEnabledClasses(unsigned __int16 *a1)
{
  int v1; // r5
  unsigned int v2; // r4
  unsigned int v4; // r1
  int v5; // [sp+8h] [bp-80h] BYREF
  char v6[8]; // [sp+10h] [bp-78h] BYREF
  char v7[8]; // [sp+20h] [bp-68h] BYREF
  int v8; // [sp+28h] [bp-60h]
  char v9[8]; // [sp+2Ch] [bp-5Ch] BYREF
  int v10; // [sp+34h] [bp-54h]
  char v11[8]; // [sp+38h] [bp-50h] BYREF
  int v12; // [sp+40h] [bp-48h]
  char v13[8]; // [sp+44h] [bp-44h] BYREF
  int v14; // [sp+4Ch] [bp-3Ch]
  int v15; // [sp+5Ch] [bp-2Ch]

  v5 = 0;
  RtlInitUnicodeString((unsigned int)v6, a1);
  v1 = IopOpenRegistryKey((int)&v5, 0, (int)v6, 131097, 0);
  if ( v1 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v7, L"SymlinkLocalToLocalEvaluation");
    v8 = 1;
    RtlInitUnicodeString((unsigned int)v9, L"SymlinkLocalToRemoteEvaluation");
    v10 = 2;
    RtlInitUnicodeString((unsigned int)v11, L"SymlinkRemoteToRemoteEvaluation");
    v12 = 8;
    RtlInitUnicodeString((unsigned int)v13, L"SymlinkRemoteToLocalEvaluation");
    LOWORD(v2) = 0;
    v14 = 4;
    while ( 1 )
    {
      v1 = ZwQueryValueKey();
      if ( v1 < 0 )
        break;
      if ( v15 )
        return sub_817970();
      v2 = (unsigned __int16)(v2 + 1);
      if ( v2 >= 4 )
      {
        __dmb(0xBu);
        do
          v4 = __ldrex((unsigned int *)&IopSymlinkEnabledTypes);
        while ( __strex(0, (unsigned int *)&IopSymlinkEnabledTypes) );
        __dmb(0xBu);
        break;
      }
    }
  }
  if ( v5 )
    ZwClose();
  return v1;
}
