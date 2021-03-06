current_directory=$(pwd)
cd $current_directory
clear

echo "Test 1"
echo ""
echo "LandTime=4"
echo "TakeOffTime=7"
echo "LandProb=.7"
echo "TakeOffProb=.8"
echo "StartTime=600"
echo "EndTime=30"
echo "CrashTime=30"
echo ""
AirSim 4 7 .7 .8 600 30 60
echo ""
echo "Test 2: Reduced Landing Queue Probability"
echo ""
echo "LandTime=4"
echo "TakeOffTime=7"
echo "LandProb=.7"
echo "TakeOffProb=.8"
echo "StartTime=600"
echo "EndTime=30"
echo "CrashTime=30"
echo ""
AirSim 4 7 .1 .8 600 30 60
echo ""
echo "Test 3"
echo ""
echo "LandTime=5"
echo "TakeOffTime=5"
echo "LandProb=.9"
echo "TakeOffProb=.9"
echo "StartTime=660"
echo "EndTime=60"
echo "CrashTime=20"
echo ""
AirSim 5 5 .9 .5 660 60 60
echo ""
echo "Test 4: Second Runway Added"
echo ""
echo "LandTime=5"
echo "TakeOffTime=5"
echo "LandProb=.4"
echo "TakeOffProb=.4"
echo "StartTime=660"
echo "EndTime=60"
echo "CrashTime=20"
echo ""
AirSim 5 5 .4 .1 660 60 60