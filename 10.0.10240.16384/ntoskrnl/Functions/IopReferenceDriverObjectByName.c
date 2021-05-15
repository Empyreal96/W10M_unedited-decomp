// IopReferenceDriverObjectByName 
 
int __fastcall IopReferenceDriverObjectByName(_WORD *a1)
{
  int result; // r0
  int v2; // r4
  int v3; // [sp+10h] [bp-28h] BYREF
  int v4; // [sp+14h] [bp-24h] BYREF
  int v5[8]; // [sp+18h] [bp-20h] BYREF

  if ( !*a1 )
    goto LABEL_3;
  v5[0] = 24;
  v5[1] = 0;
  v5[2] = (int)a1;
  v5[3] = 576;
  v5[4] = 0;
  v5[5] = 0;
  if ( ObOpenObjectByName((int)v5, IoDriverObjectType, 0, 0, 128, 0, &v3) < 0 )
    goto LABEL_3;
  v2 = ObReferenceObjectByHandle(v3, 0, IoDriverObjectType, 0, (int)&v4, 0);
  ZwClose();
  if ( v2 >= 0 )
    result = v4;
  else
LABEL_3:
    result = 0;
  return result;
}
