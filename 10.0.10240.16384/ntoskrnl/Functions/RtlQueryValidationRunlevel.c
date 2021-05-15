// RtlQueryValidationRunlevel 
 
int __fastcall RtlQueryValidationRunlevel(int a1)
{
  int v1; // r4
  int v2; // r5
  int v4; // [sp+14h] [bp-24h]
  int v5; // [sp+18h] [bp-20h]
  int v6; // [sp+1Ch] [bp-1Ch]

  v1 = 0;
  v2 = MEMORY[0xFFFF9258];
  if ( a1 && MEMORY[0xFFFF9258] != -1 && ZwOpenKey() >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v4 == 4 && v5 == 4 )
      v1 = v6;
    NtClose();
  }
  return v2 | v1;
}
