// ExpInitializePcw 
 
int __fastcall ExpInitializePcw(int a1, int a2)
{
  int result; // r0
  unsigned __int16 v3[4]; // [sp+0h] [bp-20h] BYREF
  int v4; // [sp+8h] [bp-18h]
  int v5; // [sp+Ch] [bp-14h]
  int (__fastcall *v6)(int); // [sp+10h] [bp-10h]
  int v7; // [sp+14h] [bp-Ch]

  v3[0] = 1;
  v3[1] = 1;
  v3[2] = 5;
  v4 = 1;
  v5 = 0;
  v6 = ExpPcwHostCallback;
  v7 = 0;
  result = ExRegisterHost((void ***)&ExpPcwExtensionHost, a2, v3);
  if ( result < 0 )
    result = sub_96C594();
  return result;
}
