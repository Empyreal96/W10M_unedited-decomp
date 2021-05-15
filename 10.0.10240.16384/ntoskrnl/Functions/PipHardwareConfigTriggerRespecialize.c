// PipHardwareConfigTriggerRespecialize 
 
int __fastcall PipHardwareConfigTriggerRespecialize(int a1)
{
  int v1; // r4
  int v2; // r5
  int v4[2]; // [sp+8h] [bp-18h] BYREF
  __int16 v5; // [sp+10h] [bp-10h] BYREF
  __int16 v6; // [sp+12h] [bp-Eh]
  const __int16 *v7; // [sp+14h] [bp-Ch]

  v1 = 0;
  v4[0] = 0;
  if ( a1
    || (v6 = 62,
        v5 = 60,
        v7 = L"\\Registry\\Machine\\System\\Setup",
        v2 = IopCreateRegistryKeyEx(v4, 0, (int)&v5, 983103, 0, 0),
        v1 = v4[0],
        v2 >= 0) )
  {
    v4[1] = 1;
    v6 = 26;
    v5 = 24;
    v7 = L"Respecialize";
    v2 = ZwSetValueKey();
  }
  if ( v1 )
    ZwClose();
  return v2;
}
