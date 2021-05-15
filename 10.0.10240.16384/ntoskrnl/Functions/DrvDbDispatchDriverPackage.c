// DrvDbDispatchDriverPackage 
 
int __fastcall DrvDbDispatchDriverPackage(int a1, int a2, int a3)
{
  int result; // r0
  int v4[4]; // [sp+10h] [bp-10h] BYREF

  v4[0] = 0;
  result = PnpCtxGetObjectContext(a1, a3, v4);
  if ( result >= 0 )
    result = sub_7E2EF0();
  return result;
}
