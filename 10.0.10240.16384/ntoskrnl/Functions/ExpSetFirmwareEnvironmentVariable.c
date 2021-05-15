// ExpSetFirmwareEnvironmentVariable 
 
int __fastcall ExpSetFirmwareEnvironmentVariable(int a1, int a2, int a3, int a4, int a5, char a6)
{
  int v7; // [sp+8h] [bp-28h] BYREF
  int v8[9]; // [sp+Ch] [bp-24h] BYREF

  if ( a4 )
  {
    ExLockUserBuffer(a3, a4, a6, 0, v8, &v7);
    JUMPOUT(0x8155F6);
  }
  return sub_8155F0();
}
