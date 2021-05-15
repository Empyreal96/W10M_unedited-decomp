// PiGetDefaultMessageString 
 
int __fastcall PiGetDefaultMessageString(int a1, unsigned int a2, int *a3)
{
  int v6; // r5
  int v7; // r4
  int v8; // r0
  int v9; // r3
  int v10; // r1
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r3
  int v15[2]; // [sp+8h] [bp-28h] BYREF
  int v16; // [sp+10h] [bp-20h] BYREF
  int v17; // [sp+14h] [bp-1Ch]
  _DWORD v18[6]; // [sp+18h] [bp-18h] BYREF

  RtlInitUnicodeString((unsigned int)v18, 0);
  RtlInitUnicodeString((unsigned int)&v16, 0);
  v6 = 0;
  v7 = IopGetDriverNameFromKeyNode(a1);
  if ( v7 >= 0 )
  {
    v8 = IopReferenceDriverObjectByName(v18);
    v6 = v8;
    if ( !v8 )
    {
      v7 = -1073741823;
      goto LABEL_14;
    }
    v7 = RtlFindMessage(*(_DWORD *)(v8 + 12), 11, 0, a2, v15);
    if ( v7 >= 0 )
    {
      if ( (*(_WORD *)(v15[0] + 2) & 1) != 0 )
      {
        if ( !RtlCreateUnicodeString((int)&v16, (unsigned __int16 *)(v15[0] + 4)) )
        {
LABEL_7:
          v7 = -1073741670;
          goto LABEL_14;
        }
      }
      else
      {
        RtlInitAnsiString((unsigned int)v15, v15[0] + 4);
        v7 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&v16, (unsigned __int16 *)v15, 1, v9);
        if ( v7 < 0 )
          goto LABEL_14;
      }
      v10 = (unsigned __int16)v16;
      if ( (unsigned __int16)v16 >= 4u && *(_WORD *)((unsigned __int16)v16 + v17 - 4) == 13 )
      {
        *(_WORD *)((unsigned __int16)v16 + v17 - 4) = 0;
        v10 = (unsigned __int16)(v16 - 4);
        LOWORD(v16) = v16 - 4;
      }
      v11 = ExAllocatePoolWithTag(1, v10 + 2, 538996816);
      v12 = v11;
      if ( !v11 )
        goto LABEL_7;
      memmove(v11, v17, (unsigned __int16)v16);
      v13 = (unsigned __int16)v16;
      *a3 = v12;
      *(_WORD *)(v12 + 2 * (v13 >> 1)) = 0;
      v7 = 0;
    }
  }
LABEL_14:
  RtlFreeAnsiString(v18);
  RtlFreeAnsiString(&v16);
  if ( v6 )
    ObfDereferenceObject(v6);
  return v7;
}
