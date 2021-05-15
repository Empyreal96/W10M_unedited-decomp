// KeQueryIntervalProfile 
 
int __fastcall KeQueryIntervalProfile(int a1)
{
  int result; // r0
  int v2; // [sp+0h] [bp-20h] BYREF
  int v3; // [sp+8h] [bp-18h] BYREF
  char v4; // [sp+Ch] [bp-14h]
  int v5; // [sp+10h] [bp-10h]

  if ( a1 == 1 )
    return KiProfileAlignmentFixupInterval;
  v3 = a1;
  if ( off_617B54(1, 16, &v3, &v2) >= 0 && v4 )
    result = v5;
  else
    result = 0;
  return result;
}
