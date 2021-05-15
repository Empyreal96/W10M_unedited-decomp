// PiDevCfgResolveVariableGenerateGuid 
 
int __fastcall PiDevCfgResolveVariableGenerateGuid(int a1, int a2, _DWORD *a3)
{
  int v4; // r0
  int v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r0
  int v9; // r6
  int v11; // [sp+0h] [bp-30h] BYREF
  int v12; // [sp+4h] [bp-2Ch]
  char v13[40]; // [sp+8h] [bp-28h] BYREF

  v11 = 0;
  v12 = 0;
  v4 = ExUuidCreate((int)v13);
  v5 = v4;
  if ( v4 == 1073872982 || v4 >= 0 )
  {
    v5 = RtlStringFromGUIDEx((int)v13, (int)&v11, 1);
    if ( v5 >= 0 )
    {
      v5 = RtlUpcaseUnicodeString((unsigned __int16 *)&v11, (unsigned __int16 *)&v11, 0, v6);
      if ( v5 >= 0 )
      {
        v7 = (unsigned __int16)v11 + 2;
        v8 = ExAllocatePoolWithTag(1, v7, 1667526736);
        v9 = v8;
        if ( v8 )
        {
          memmove(v8, v12, v7);
          a3[4] = 1;
          a3[5] = v7;
          a3[6] = v9;
        }
        else
        {
          v5 = -1073741670;
        }
      }
    }
  }
  RtlFreeAnsiString(&v11);
  return v5;
}
