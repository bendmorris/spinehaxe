import haxe.unit.TestRunner;

class TestMain
{
    public static function main ()
    {
        var runner = new TestRunner();

        // Register all our test cases
        runner.add(new LoadJSONTest());
        runner.add(new SkeletonDataTest());
        runner.add(new SlotDataTest());
        runner.add(new BoneTest());
        runner.add(new ColorTest());

        // Run them and and exit with the right return code
        var success = runner.run();
    }
}
