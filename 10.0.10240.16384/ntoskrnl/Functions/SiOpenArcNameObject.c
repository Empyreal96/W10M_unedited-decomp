// SiOpenArcNameObject 
 
int __fastcall SiOpenArcNameObject(unsigned __int16 *a1, _DWORD *a2)
{
  int result; // r0
  int v4; // [sp+0h] [bp-30h]
  char v5[8]; // [sp+8h] [bp-28h] BYREF
  int v6; // [sp+10h] [bp-20h]
  int v7; // [sp+14h] [bp-1Ch]
  char *v8; // [sp+18h] [bp-18h]
  int v9; // [sp+1Ch] [bp-14h]
  int v10; // [sp+20h] [bp-10h]
  int v11; // [sp+24h] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v5, a1);
  v6 = 24;
  v7 = 0;
  v9 = 576;
  v8 = v5;
  v10 = 0;
  v11 = 0;
  result = ZwOpenSymbolicLinkObject();
  if ( result >= 0 )
  {
    *a2 = v4;
  }
  else if ( result != -1073741801 && result != -1073741670 )
  {
    result = -1073740718;
  }
  return result;
}
