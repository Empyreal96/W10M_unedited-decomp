// ExpQueryLegacyDriverInformation 
 
int __fastcall ExpQueryLegacyDriverInformation(int a1, unsigned int *a2)
{
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r6
  unsigned __int16 *v8; // [sp+0h] [bp-30h] BYREF
  _DWORD v9[3]; // [sp+4h] [bp-2Ch] BYREF
  unsigned __int16 v10; // [sp+10h] [bp-20h] BYREF
  int v11; // [sp+14h] [bp-1Ch]
  int anonymous1; // [sp+38h] [bp+8h]
  unsigned int *varsC; // [sp+3Ch] [bp+Ch]

  anonymous1 = a1;
  varsC = a2;
  v8 = 0;
  v4 = IoGetLegacyVetoList((unsigned int *)&v8, v9);
  if ( v4 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)&v10, v8);
    v5 = v10;
    v6 = v10 + 12;
    v9[1] = v6;
    if ( v6 <= *a2 )
    {
      *(_DWORD *)a1 = v9[0];
      *(_WORD *)(a1 + 4) = v5;
      *(_DWORD *)(a1 + 8) = a1 + 12;
      memmove(a1 + 12, v11, v5);
    }
    else
    {
      v4 = -2147483643;
    }
    if ( v8 )
      ExFreePoolWithTag((unsigned int)v8);
    *a2 = v6;
  }
  return v4;
}
