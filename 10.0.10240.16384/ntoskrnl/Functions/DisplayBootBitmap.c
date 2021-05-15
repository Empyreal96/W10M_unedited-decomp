// DisplayBootBitmap 
 
int __fastcall DisplayBootBitmap(int a1)
{
  int v1; // r5
  int result; // r0
  int v3; // r6
  int v4; // r8
  int v5; // r8
  int v6; // r6
  int v7; // r0
  int v8[6]; // [sp+10h] [bp-18h] BYREF

  v1 = 0;
  if ( byte_64A414 )
    return sub_5507C8();
  ShowProgressBar = 0;
  if ( a1 )
  {
    InbvSetTextColor(15);
    InbvSolidColorFill(0, 0, 639, 479, 0);
    InbvSolidColorFill(0, 421, 639, 479, 0);
    v3 = InbvGetResourceAddress(6);
    v4 = InbvGetResourceAddress(7);
    v1 = 0;
    result = InbvSetScrollRegion(32, 80, 631, 400);
    if ( v4 )
      result = InbvBitBlt(v4, 0, 419);
    if ( v3 )
      result = InbvBitBlt(v3, 0, 0);
LABEL_18:
    if ( !byte_64A414 )
      return result;
    goto LABEL_19;
  }
  if ( !InbvIsBootDriverInstalled() )
    return InbvReleaseResources();
  dword_637604 = (int)DisplayFilter;
  v5 = InbvGetResourceAddress(1);
  result = InbvGetResourceAddress(4);
  v6 = result;
  if ( v5 )
  {
    v1 = 1;
    result = InbvBitBlt(v5, 0, 0);
  }
  if ( v6 )
    result = InbvBitBlt(v6, 0, 0);
  if ( !byte_64A414 )
  {
    result = PsCreateSystemThread(v8, 0, 0, 0, 0, InbvRotateGuiBootDisplay, 0);
    if ( result >= 0 )
    {
      result = ZwClose();
      byte_64A414 = 1;
    }
    goto LABEL_18;
  }
LABEL_19:
  v7 = InbvAcquireLock(result);
  RotBarSelection = v1;
  if ( v1 == 1 )
    v7 = RotBarInit(v7);
  return InbvReleaseLock(v7);
}
